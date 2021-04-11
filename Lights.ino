#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

Servo servo;

const char* ssid = "SSID";
const char* password = "PASSWORD";

const int ON = 60; 
const int N = 94;
const int OFF = 110; 

ESP8266WebServer server(80);

void SetServo() {
  String servo_status = server.arg("servo");

  bool url_check = false;
  if((servo_status == "ON")||(servo_status == "OFF"))
    url_check = true;

  if (servo_status == "ON") {
    servo.write(ON);
    delay(200);
    servo.write(N);
  } else if (servo_status == "OFF") {
    servo.write(OFF);
    delay(200);
    servo.write(N);
  }
  if (url_check)
    server.send(200, "text/plain", "Light state changed! (" + String(millis()) + ")");
  else
    server.send(200, "text/plain", "Light state unchanged! (" + String(millis()) + ")");
}

void setup(void) {
  servo.attach(4);
  servo.write(N);
  Serial.begin(115200);
  WiFi.begin(ssid,password);

  server.on("/setservo", HTTP_GET, SetServo);

  server.begin();
}

void loop(void) {
  server.handleClient();
}
