export async function onRequestGet(context) {
  const cf = context.request.cf || {};
  const data = {
    status: 'healthy',
    system: 'UzOS Cloud 2.0.4 WebOS',
    infrastructure: 'Cloudflare Pages Global Edge',
    telemetry: '0 bytes (100% Zero-Telemetry)',
    sovereignty: 'Republic of Uzbekistan Digital Space',
    edgeDataCenter: cf.colo || 'TAS (Tashkent / Edge)',
    httpProtocol: cf.httpProtocol || 'HTTP/3',
    timestamp: new Date().toISOString()
  };

  return new Response(JSON.stringify(data, null, 2), {
    headers: {
      'Content-Type': 'application/json; charset=utf-8',
      'X-Content-Type-Options': 'nosniff',
      'X-Frame-Options': 'SAMEORIGIN',
      'Access-Control-Allow-Origin': '*'
    }
  });
}
