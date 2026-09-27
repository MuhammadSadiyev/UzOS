import React from 'react';
import ReactDOM from 'react-dom/client';
import '@telegram-apps/telegram-ui/dist/styles.css';
import App from './App.jsx';

const rootEl = document.getElementById('root');
if (rootEl) {
  ReactDOM.createRoot(rootEl).render(
    <React.StrictMode>
      <App />
    </React.StrictMode>
  );
}
