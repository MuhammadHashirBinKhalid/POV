// Our own Header File
#include <POV.h>


//Constructor
//POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1){
//_num_leds=number_of_led_per_strip;
//_num_strips=1;
//}

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1,uint8_t d2,uint8_t c2){
// _num_leds=number_of_led;
// _num_strips=2;
// }

POV::POV(int number_of_led_per_strip, uint8_t d1, uint8_t c1, uint8_t d2, uint8_t c2, uint8_t d3, uint8_t c3) {
  _num_leds = number_of_led_per_strip;
  _num_strips = 3;
}

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4){
// _num_leds=number_of_led;
// _num_strips=4;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5){
// _num_leds=number_of_led;
// _num_strips=5;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6){
// _num_leds=number_of_led;
// _num_strips=6;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7){
// _num_leds=number_of_led;
// _num_strips=7;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8){
// _num_leds=number_of_led;
// _num_strips=8;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8, uint8_t d9,uint8_t c9){
// _num_leds=number_of_led;
// _num_strips=9;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8, uint8_t d9,uint8_t c9, uint8_t d10,uint8_t c10){
// _num_leds=number_of_led;
// _num_strips=10;
// }

// POV::POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8, uint8_t d9,uint8_t c9, uint8_t d10,uint8_t c10, uint8_t d11,uint8_t c11){
// _num_leds=number_of_led;
// _num_strips=11;
// }

void POV::init(int sensorpin) {
  //1st method
  _sensorpin = sensorpin;
  int _pins[1][2] = {{3, 4}};
 // for(int i=0;i<=_num_strips;i++)
  //{
  FastLED.addLeds<APA102, D1, D2>(leds1, 8);
  FastLED.addLeds<APA102, D5, D6>(leds2, 8);
  FastLED.addLeds<APA102, D3, D8>(leds3, 8);
  //}
  setBrightness(BRIGHTNESS);
}

void POV::setBrightness(int brightness) {
  FastLED.setBrightness(brightness);
}

void POV::run() {
  if (_State == HIGH) {
    _previous_micros1 = micros();
    _T = (_previous_micros1 - _previous_micros4) / 3.0;
    _dottime = _T / 73000.0 * _fontsize;

    _previous_micros4 = micros();
    _m1 = 0;
    _i1 = 0;
    _b1init = 0; _b2init = 0; _b3init = 0;
    _State = LOW;
  }
  _current_micros = micros();

  if (_current_micros - _previous_micros4 >= _T) {
    if (!_b2init) {
      _i2 = 0;
      _m2 = 0;
      _b2init = 1;
    }
  }
  if (_current_micros - _previous_micros4 >= (2 * _T)) {
    if (!_b3init) {
      _i3 = 0;
      _m3 = 0;
      _b3init = 1;
    }
  }

  if ((_current_micros - _previous_micros1 >= _dottime) && (_m1 < 48) && (_i1 < 23)) {
    printLetterb1(_alpha[_toprint[_i1]]);
    if (_m1 >= 48) {
      _i1++;
      _m1 = 0;
    }
    _previous_micros1 = micros();
  }

  if ((_current_micros - _previous_micros2 >= _dottime) && (_m2 < 48) && (_i2 < 23)) {
    printLetterb2(_alpha[_toprint[_i2]]);
    if (_m2 >= 48) {
      _i2++;
      _m2 = 0;
    }
    _previous_micros2 = micros();
  }

  if ((_current_micros - _previous_micros3 >= _dottime) && (_m3 < 48) && (_i3 < 23)) {
    printLetterb3(_alpha[_toprint[_i3]]);
    if (_m3 >= 48) {
      _i3++;
      _m3 = 0;
    }
    _previous_micros3 = micros();
  }
}


void POV::server() {
  WiFiServer _server(80);
  WiFiClient _client = _server.available();
  if (!_client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!_client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String command1 = _client.readStringUntil('/');
  String command = _client.readStringUntil('/');
  Serial.println(command);
  if (command == "text") {
    _value1 = _client.readStringUntil('/');
    _value1.replace("%20", " ");
    _value1.toCharArray(_charBuf, 70) ;
    Serial.println(_value1);
    //   Serial.println("charbuf ");
    //  Serial.print(charBuf);
    for (int i = 0; i < _value1.length(); i++)
    {
      _tempvalue = _charBuf[i];
      //Serial.println("tempvalue: ");
      //Serial.println(tempvalue);}
      if (_tempvalue > 64) {
        _tempvalue = _tempvalue - 65 + 10;
      }
      else if (_tempvalue > 47) {
        _tempvalue = _tempvalue - 48;
      }
      if (_tempcount < _max_dig) {
        _toprint[_tempcount] = _charBuf[_tempcount];
        _tempcount++;
      }
      if (_tempcount >= _max_dig) {
        _tempcount = 0;
      }
    }
    _value = _client.readStringUntil('/');
    _value.replace("%20", " ");
    Serial.println("Dottime: ");
    _value.toCharArray(_charBuf, 70) ;
    _dottime = _value.toInt();
    Serial.println(_dottime);
  }
  else {  // Prepare the response
    String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    s += _file1;
    _client.flush();
    // Send the response to the client
    while (s.length() > 2000)
    {
      String dummy = s.substring(0, 2000);
      _client.print(dummy);
      s.replace(dummy, " ");
    }

    _client.print(s);
    delay(1);
    Serial.println("Client disconnected");

    // The client will actually be disconnected
    // when the function returns and 'client' object is destroyed
  }
}

void POV::setState() {
  _State = HIGH;
}

void POV::printLetterb1(bool letter[])
{
  for (int Pin = 0; Pin <=_num_leds; Pin++) {
    if (letter[_m1] == 1) {
      leds1[Pin] = CRGB::Green;
    }
    else {
      leds1[Pin] = CRGB::Black;
    }
    _m1++;
  }
  FastLED.show();
}


void POV::printLetterb2(bool letter[])
{
  for (int Pin = 0; Pin <= _num_leds; Pin++) {
    if (letter[_m2] == 1) {
      leds2[Pin] = CRGB::Green;
    }
    else {
      leds2[Pin] = CRGB::Black;
    }
    _m2++;
  }
  FastLED.show();
}

void POV::printLetterb3(bool letter[])
{
  for (int Pin = 0; Pin <=_num_leds; Pin++) {
    if (letter[_m3] == 1) {
      leds3[Pin] = CRGB::Green;
    }
    else {
      leds3[Pin] = CRGB::Black;
    }
    _m3++;
  }
  FastLED.show();
}
