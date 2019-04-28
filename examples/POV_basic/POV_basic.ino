#include <ESP8266WiFi.h>
#include <FastLED.h>
#include <POV.h>
POV pov(8, D1,D2,D5,D6,D3,D8);

const char* ssid = "";
const char* password = "";


void setup() {
  //attachInterrupt(digitalPinToInterrupt(sensor), ISR, CHANGE);

  Serial.begin(115200);
    pov.init(D7);
    pov.setState();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {

pov.server();
pov.run();
}

/*void ISR () // handle pin change interrupt for D0 to D7 here
{
  if (mybool == 0) {
    State = 1;
    mybool = 1;
  }
  else mybool = 0;
}*/
