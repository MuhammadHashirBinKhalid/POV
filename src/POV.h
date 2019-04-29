/***************************************************
Copyrights 2019
Muhammad Hashir Bin Khalid (github: MuhammadHashirBinKhalid)
***************************************************/

#ifndef POV_H_
#define POV_H_

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <FastLED.h>
// #include <stdint.h>

// Directives

// Variables

// Constants
#define BRIGHTNESS 60


// Classes
class POV {

public:
//     explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8, uint8_t d9,uint8_t c9, uint8_t d10,uint8_t c10, uint8_t d11,uint8_t c11);
   
//     explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8, uint8_t d9,uint8_t c9, uint8_t d10,uint8_t c10);
//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8, uint8_t d9,uint8_t c9);
//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7
// , uint8_t d8,uint8_t c8);
//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6, uint8_t d7,uint8_t c7);
   
//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5, uint8_t d6,uint8_t c6);

//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4, uint8_t d5,uint8_t c5);

//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3
// , uint8_t d4,uint8_t c4);
    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2, uint8_t d3,uint8_t c3);
//    explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1, uint8_t d2,uint8_t c2);
  // explicit POV(int number_of_led_per_strip, uint8_t d1,uint8_t c1);
   
    void init(int sensorpin);
    void setState();
    void setBrightness(int brightness);
    void run(); 
    int _fontsize=2000;
    long _dottime;
    void server();
protected:
    
private:
    bool _State;
    void printLetterb1(bool letter[]);
    void printLetterb2(bool letter[]);
    void printLetterb3(bool letter[]);
    int _num_leds;
    int _num_strips;
    int _sensorpin;
    unsigned long _previous_micros1,_previous_micros2,_previous_micros3,_previous_micros4,_T;
    unsigned long _current_micros;
    int _m1=0,_m2=0,_m3=0,_i1=0,_i2=0,_i3=0;
    bool _b1init=0,_b2init=0,_b3init=0;
    CRGB leds1[8]; 
    CRGB leds2[8]; 
    CRGB leds3[8]; 
    char _charBuf[60];
    String _value; 
    String _value1; 
    int _ivalue = 0;
    int _tempcount = 0;
    int _tempvalue=0;
    int _max_dig = 23;
    int _toprint[22] = {17, 14, 21, 21, 24, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36};
    bool _alpha[37][48] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //0
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //1
  {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //2
  {1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //3
  {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //4
  {1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //5
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //6
  {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //8
  {1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //9

  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //A=10
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //B=11
  {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //C=12
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //D=13
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //E=14
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //F=15
  {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //G=16
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //H=17
  {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //I=18
  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //J=19
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //K=20
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //L=21
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //M=22
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //N=23
  {0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //O=24
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //P=25
  {0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //Q=26
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //R=27
  {0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //S=28
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //T=29
  {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //U=30
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //V=31
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //W=32
  {1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //X=33
  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Y=34
  {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //Z=35

  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} //Empty = 36
};
   String _file1=
"<!DOCTYPE html>\r\n"
"<html lang=\"en\">\r\n"
"    <head>\r\n"
"        <meta charset=\"utf-8\">\r\n"
"        <title>POV Display</title>\r\n"
"        <script>\r\n"
"\r\n"
"        strLine1 = \"\";\r\n"
"        strLine2 = \"\";\r\n\r\n"
"        strLine3 = \"\";\r\n"
"        strLine4 = \"\";\r\n\r\n"
"        \r\n"
"        function SendText()\r\n"
"        {\r\n"
"            var request = new XMLHttpRequest();\r\n"
"            \r\n"
"            strLine1 = document.getElementById(\"txt_form\").line.value;\r\n"
"            strLine2 = document.getElementById(\"txt_form\").quantity.value;\r\n"
"            \r\n"
"            strLine3 = document.getElementById(\"txt_form\").f1.value;\r\n"
"            strLine4 = document.getElementById(\"txt_form\").f2.value;\r\n"
"            \r\n"
"            request.open(\"GET\", \"text/\" + strLine1 +\"/\"+ strLine2 + \"/\"+ strLine3 + \"/\"+ strLine4 + \"/\", true);\r\n"
"            request.send(null);\r\n"
"        }\r\n"
"        </script>\r\n"
"    </head>\r\n"
"\r\n"
"    <body \">\r\n"
"        <p><b>Enter the fields:</b></p>\r\n"
"        <form id=\"txt_form\" name=\"frmText\">\r\n"
"            <label>Text to Display: <input type=\"text\" name=\"line\" size=\"60\" maxlength=\"60\" /></label>\r\n"
"            <label>Dot Time: <input type=\"number\" name=\"quantity\" size=\"60\" maxlength=\"60\" /></label>\r\n"
"            <label>F1(Text): <input type=\"text\" name=\"f1\" size=\"60\" maxlength=\"60\" /></label>\r\n"
"            <label>F2(Number): <input type=\"number\" name=\"f2\" size=\"60\" maxlength=\"60\" /></label>\r\n"
"         </form>\r\n"
"        <br />\r\n"
"        <input type=\"submit\" value=\"Send\" onclick=\"SendText()\" />\r\n"
"\r\n"
"</html>\r\n";


};

#endif  // POV_H_
