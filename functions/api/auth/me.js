export async function onRequestGet() {
  return new Response(JSON.stringify({
    authenticated: true,
    user: {
      username: 'uzos_admin',
      fullName: 'UzOS Foydalanuvchisi',
      oneIdVerified: true,
      securityLevel: 'AES-GCM 256 + Zero-Telemetry'
    }
  }, null, 2), {
    headers: {
      'Content-Type': 'application/json; charset=utf-8',
      'X-Content-Type-Options': 'nosniff',
      'X-Frame-Options': 'SAMEORIGIN',
      'Access-Control-Allow-Origin': '*'
    }
  });
}
