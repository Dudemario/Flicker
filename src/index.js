import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { SpeechProvider } from '@speechly/react-client';

ReactDOM.render(
  //<SpeechProvider appId="b043f80e-2035-4d56-adee-dc16fcaa4c92" language="en-US">
  <React.StrictMode>
    <App />
  </React.StrictMode>,
 // </SpeechProvider>,
  document.getElementById('root')
  
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
