import http from 'http';
import fs from 'fs';
import path from 'path';

const PORT = process.env.PORT || 8080;
const MIME = {
  '.html': 'text/html; charset=utf-8',
  '.css': 'text/css; charset=utf-8',
  '.js': 'text/javascript; charset=utf-8',
  '.json': 'application/json; charset=utf-8',
  '.svg': 'image/svg+xml',
  '.png': 'image/png',
  '.jpg': 'image/jpeg',
  '.ico': 'image/x-icon'
};

const baseDir = fs.existsSync(path.join(import.meta.dirname, 'dist')) 
  ? path.join(import.meta.dirname, 'dist') 
  : import.meta.dirname;

const server = http.createServer((req, res) => {
  let reqPath = decodeURI(req.url.split('?')[0]);
  if (reqPath === '/' || reqPath === '') reqPath = '/index.html';
  
  let filePath = path.join(baseDir, reqPath);
  if (!fs.existsSync(filePath) && fs.existsSync(path.join(import.meta.dirname, reqPath))) {
    filePath = path.join(import.meta.dirname, reqPath);
  }

  const ext = path.extname(filePath).toLowerCase();

  fs.readFile(filePath, (err, data) => {
    if (err) {
      res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' });
      res.end('404 Not Found');
    } else {
      res.writeHead(200, { 'Content-Type': MIME[ext] || 'application/octet-stream' });
      res.end(data);
    }
  });
});

server.listen(PORT, () => {
  console.log(`UzOS Cloud Server running at http://localhost:${PORT}/ (serving from ${baseDir})`);
});
