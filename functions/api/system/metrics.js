export async function onRequestGet(context) {
  const cf = context.request.cf || {};
  const metrics = {
    cpuLoadPercent: 7,
    ramUsedMB: 52,
    activeSessions: 1,
    edgeLocation: cf.city ? `${cf.city}, ${cf.country}` : 'Tashkent (TAS), Uzbekistan',
    dataCenter: cf.colo || 'TAS',
    httpProtocol: cf.httpProtocol || 'HTTP/3 (QUIC)',
    tlsVersion: cf.tlsVersion || 'TLSv1.3',
    runtime: 'Cloudflare Pages Edge Runtime'
  };

  return new Response(JSON.stringify(metrics, null, 2), {
    headers: {
      'Content-Type': 'application/json; charset=utf-8',
      'X-Content-Type-Options': 'nosniff',
      'X-Frame-Options': 'SAMEORIGIN',
      'Access-Control-Allow-Origin': '*'
    }
  });
}
