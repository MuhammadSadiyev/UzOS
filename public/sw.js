/* ==============================================================================
   UzOS Cloud (WebOS) — Production Service Worker
   Offline Execution Engine, Static Asset Cache-First & Network Fallback
   ============================================================================== */

const CACHE_NAME = 'uzos-cloud-v2.0.4';

const PRECACHE_ASSETS = [
  '/',
  '/desktop.html',
  '/index.html',
  '/manifest.webmanifest',
  '/favicon.svg',
  '/icon.svg'
];

// Install: precache foundational shell
self.addEventListener('install', (event) => {
  event.waitUntil(
    caches.open(CACHE_NAME).then((cache) => {
      return cache.addAll(PRECACHE_ASSETS).catch((err) => {
        console.warn('[UzOS SW] Precache warning:', err);
      });
    }).then(() => self.skipWaiting())
  );
});

// Activate: clean obsolete caches and claim clients immediately
self.addEventListener('activate', (event) => {
  event.waitUntil(
    caches.keys().then((keys) => {
      return Promise.all(
        keys.map((key) => {
          if (key !== CACHE_NAME) {
            console.log('[UzOS SW] Purging legacy cache:', key);
            return caches.delete(key);
          }
        })
      );
    }).then(() => self.clients.claim())
  );
});

// Fetch: Smart Cache Strategy
self.addEventListener('fetch', (event) => {
  // Only handle GET requests and http/https schemes
  if (event.request.method !== 'GET') return;
  const url = new URL(event.request.url);

  // Ignore cross-origin telemetry or external non-essential calls if any
  if (url.origin !== self.location.origin) {
    return;
  }

  // HTML navigation: Network-first with cache fallback
  if (event.request.mode === 'navigate' || event.request.destination === 'document') {
    event.respondWith(
      fetch(event.request)
        .then((response) => {
          if (response && response.status === 200) {
            const copy = response.clone();
            caches.open(CACHE_NAME).then((cache) => cache.put(event.request, copy));
          }
          return response;
        })
        .catch(async () => {
          const cached = await caches.match(event.request);
          if (cached) return cached;
          return caches.match('/desktop.html') || caches.match('/');
        })
    );
    return;
  }

  // Static Assets (CSS, JS, Fonts, Images): Cache-first with network fallback
  event.respondWith(
    caches.match(event.request).then((cached) => {
      if (cached) {
        // Fetch in background to revalidate (stale-while-revalidate for local scripts)
        fetch(event.request).then((networkResponse) => {
          if (networkResponse && networkResponse.status === 200) {
            caches.open(CACHE_NAME).then((cache) => cache.put(event.request, networkResponse));
          }
        }).catch(() => {});
        return cached;
      }

      return fetch(event.request).then((networkResponse) => {
        if (!networkResponse || networkResponse.status !== 200 || networkResponse.type !== 'basic') {
          return networkResponse;
        }
        const responseToCache = networkResponse.clone();
        caches.open(CACHE_NAME).then((cache) => {
          cache.put(event.request, responseToCache);
        });
        return networkResponse;
      });
    })
  );
});
