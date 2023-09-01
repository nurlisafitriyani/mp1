/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "LEB_EVO_COM";
const char* password = "satuduatiga";

ESP8266WebServer server (80);


void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

server.on("/", []() {
  server.send(200, "text/html", "<html>\
  <head>\
  <title>Beranda</title>\
  <style>\
  h1 { color: red; }\
  </style>\
  </head>\
  <body>\
  <h1>Beranda</h1>\
  <a href='/'>Beranda</a>|<a href='/profil'>profil</a>\
  </body>\
  </html>");
});
server.on("/profil", []() {
  server.send(200, "text/html", "<html>\
  <head>\
  <title>profil</title>\
  <style>\
  h1 { color: red; }\
  </style>\
  </head>\
  <body>\
  <h1>profil</h1>\
  <a href='/'>profil</a>|<a href='/beranda'>beranda</a>\
  </body>\
  </html>");
});



server.begin();
}


void loop() {
  server.handleClient();

} 
