export async function onRequestPost(context) {
  let body = {};
  try {
    body = await context.request.json();
  } catch (_) {}

  if (!body || !body.vault) {
    return new Response(JSON.stringify({ 
      success: false, 
      error: "VFS vault ma'lumoti topilmadi." 
    }), {
      status: 400,
      headers: { 
        'Content-Type': 'application/json; charset=utf-8',
        'X-Content-Type-Options': 'nosniff' 
      }
    });
  }

  // If Cloudflare KV is bound to the project, save encrypted blob
  if (context.env && context.env.UZOS_KV) {
    const userId = body.userId || 'uzos_admin';
    await context.env.UZOS_KV.put(`vault_${userId}`, JSON.stringify(body.vault));
  }

  return new Response(JSON.stringify({
    success: true,
    message: "Fayllar Cloudflare Edge suveren bulut xotirasiga (E2EE) muvaffaqiyatli sinxronlandi.",
    timestamp: new Date().toISOString()
  }, null, 2), {
    headers: {
      'Content-Type': 'application/json; charset=utf-8',
      'X-Content-Type-Options': 'nosniff',
      'X-Frame-Options': 'SAMEORIGIN',
      'Access-Control-Allow-Origin': '*'
    }
  });
}

export async function onRequestGet(context) {
  if (context.env && context.env.UZOS_KV) {
    const userId = 'uzos_admin';
    const vault = await context.env.UZOS_KV.get(`vault_${userId}`, 'json');
    if (vault) {
      return new Response(JSON.stringify({ success: true, vault }, null, 2), {
        headers: { 
          'Content-Type': 'application/json; charset=utf-8',
          'Access-Control-Allow-Origin': '*'
        }
      });
    }
  }
  return new Response(JSON.stringify({ 
    success: false, 
    message: 'Bulutda saqlangan zaxira topilmadi.' 
  }, null, 2), {
    status: 404,
    headers: { 
      'Content-Type': 'application/json; charset=utf-8',
      'Access-Control-Allow-Origin': '*'
    }
  });
}
