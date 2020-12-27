#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include <EEPROM.h>

#include "index.h"




AsyncWebServer server(80);

// REPLACE WITH YOUR NETWORK CREDENTIALS
const char* ssid = "ESPAP";
const char* password = "thereisnospoon";

const char* PARAM_INPUT_1 = "ssid";
const char* PARAM_INPUT_2 = "password";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
//  Serial.println(WiFi.softAP(ssid, password) ? "[+]Access Point Ready" : "[!]Failed");
  // Send web page with input fields to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", WEB_PAGE);
  });

  // Send a GET request to <ESP_IP>/get?input1=<inputMessage>
   server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage, inputParam;
     String qsid, qpass;
     // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
     if (request->hasParam(PARAM_INPUT_1)) {
       inputMessage = request->getParam(PARAM_INPUT_1)->value();
//       Serial.print(inputMessage);
       inputParam = PARAM_INPUT_1;
          for (int i = 0; i < inputMessage.length(); ++i)
            {
              EEPROM.write(i, inputMessage[i]);
              Serial.print("Wrote: ");
              Serial.println(inputMessage[i]); 
            } 
     }
     // GET input2 value on <ESP_IP>/get?input2=<inputMessage>
     else if (request->hasParam(PARAM_INPUT_2)) {
       inputMessage = request->getParam(PARAM_INPUT_2)->value();
//       Serial.print(inputMessage);
       inputParam = PARAM_INPUT_2;
     }
     else {
       inputMessage = "No message sent";
       inputParam = "none";
     }
     Serial.println(inputMessage);
     Serial.print("----------");
     request->send(200, "text/html", "HTTP GET request sent to your ESP on input field (" 
                                      + inputParam + ") with value: " + inputMessage +
                                      "<br><a href=\"/\">Return to Home Page</a>");
   });
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
    
}