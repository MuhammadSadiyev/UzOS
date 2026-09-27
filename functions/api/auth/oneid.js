export async function onRequestPost(context) {
  let body = {};
  try {
    body = await context.request.json();
  } catch (_) {}

  const userProfile = {
    sessionId: crypto.randomUUID(),
    authMethod: 'OneID.uz (Yagona Identifikatsiya Tizimi)',
    pinfl: body.pinfl || '32801980000000',
    fullName: body.fullName || "Muhammad Sadiyev (UzOS Admin)",
    role: 'Suveren Foydalanuvchi',
    loginTime: new Date().toISOString()
  };

  return new Response(JSON.stringify({
    success: true,
    message: 'OneID orqali muvaffaqiyatli kirildi.',
    user: userProfile
  }, null, 2), {
    headers: {
      'Content-Type': 'application/json; charset=utf-8',
      'X-Content-Type-Options': 'nosniff',
      'X-Frame-Options': 'SAMEORIGIN',
      'Access-Control-Allow-Origin': '*'
    }
  });
}
