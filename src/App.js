import React from "react";
import logo from './logo.svg';
import './App.css';
import { render } from 'react-dom'

export default class App extends React.Component{
  render() {
    return (
      <div>
        <h1><a href="http://192.168.2.71/setservo?servo=ON" target="_blank">Lights On</a></h1>
        <h1><a href="http://192.168.2.71/setservo?servo=OFF" target="_blank">Lights Off</a></h1>
      </div>
    )
  }
}