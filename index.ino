/// @file    Pacifica.ino
/// @brief   Gentle, blue-green ocean wave animation
/// @example Pacifica.ino

//
//  "Pacifica"
//  Gentle, blue-green ocean waves.
//  December 2019, Mark Kriegsman and Mary Corey March.
//  For Dan.
//

#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define DATA_PIN 6
#define NUM_LEDS 88
#define MAX_POWER_MILLIAMPS 500
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define NUM_REPEAT 5

//////////////////////////////////////////////////////////////////////////

CRGB leds[NUM_LEDS];

uint8_t patternCounter = 0;
bool isRunning = false;

void setup() {
  delay(300);  // 3 second delay for boot recovery, and a moment of silence
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(9600);
}

void loop() {

  patternCounter = random8(3);

  switch (patternCounter) {
    case 0:
      runPattern_1();
      break;
    case 1:
      runNumber_1();
      break;
    case 2:
    runPong_1();
    break;
  }
  //patternCounter = 2;
}

void runPattern_1() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    Serial.println(i);
    Serial.println("BLUE Loop");
    Serial.flush();
    //delay(20);
  }

  FastLED.show();
  delay(4000);



  for (int i = 7; i < NUM_LEDS + 4; i++) {
    leds[i] = CRGB::Blue;
    leds[i - 1] = CRGB::Red;
    leds[i - 2] = CRGB::Red;
    leds[i - 3] = CRGB::Red;
    leds[i - 4] = CRGB::Orange;
    leds[i - 5] = CRGB::Orange;
    leds[i - 6] = CRGB::Orange;
    leds[i - 7] = CRGB::Orange;

    FastLED.show();
    Serial.println(i);
    Serial.println("Frwad lop fo");
    Serial.flush();
    delay(40);
  }
  delay(4000);
  Serial.println("Frwad lop");
  Serial.flush();

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    //delay(20);
  }

  FastLED.show();
  delay(4000);

  for (int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = CRGB::Green;

    leds[i - 1] = CRGB::Red;
    // leds[i - 2] = CRGB::Red;
    // leds[i - 3] = CRGB::Red;
    // leds[i - 4] = CRGB::Orange;
    // leds[i - 5] = CRGB::Orange;
    // leds[i - 6] = CRGB::Orange;
    // leds[i - 7] = CRGB::Orange;
    FastLED.show();
    delay(40);
    Serial.println(i);
  }
  delay(4000);

  Serial.flush();
  //leds[i] = CRGB(i * 20, i * 10, i * 30);
}

void runNumber_1() {
  int numarr[10][16] = {  { 70, 71, 72, 73, 58, 61, 48, 48, 51, 51, 36, 26, 27, 28, 29, 39},
                          { 27, 38, 49, 60, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71},
                          { 26, 27, 28, 29, 39, 48, 49, 50, 51, 58, 73, 70, 71, 72, 72, 72},
                          { 70, 71, 72, 73, 58, 48, 49, 50, 51, 36, 26, 27, 28, 29, 29, 29},
                          { 70, 61, 48, 49, 50, 51, 73, 58, 36, 29, 29, 29, 29, 29, 29, 29},
                          { 73, 72, 71, 70, 61, 48, 49, 50, 51, 36, 29, 28, 27, 26, 26, 26},
                          { 73, 72, 71, 70, 61, 48, 49, 50, 51, 36, 29, 28, 27, 26, 39, 39},
                          { 70, 71, 72, 73, 58, 51, 36, 29, 29, 29, 29, 29, 29, 29, 29, 29},
                          { 70, 71, 72, 73, 58, 61, 48, 49, 51, 50, 36, 26, 27, 28, 29, 39},
                          { 70, 71, 72, 73, 58, 61, 48, 49, 51, 50, 36, 26, 27, 28, 29, 29} };

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();

    //delay(20);
  }
  delay(1000);

  for (int i = 9; i > -1; i--) {

    FastLED.clear();

    for (int k = 0; k < NUM_LEDS; k++) {
      leds[k] = CRGB::Red ;
      FastLED.show();
      //delay(10);
      //delay(20);
    }
    delay(1000);

    for (int j = 0; j < 16; j++) {
      leds[numarr[i][j]] = CRGB::Orange;
    }
    FastLED.show();
    delay(3000);
  }
}


void runPong_1() {
  int numpong[15] = {87,67, 63, 47, 39, 27, 15, 7, 13, 31, 33, 53, 57, 73, 81};

  FastLED.clear();

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();

    //delay(20);
  }
  delay(1000);

    for (int j = 0; j < 15; j++) {
      leds[numpong[j]] = CRGB::Red;
      FastLED.show();
      delay(80);

      leds[numpong[j]] = CRGB::Blue;
      FastLED.show();

      if (numpong[j] == 81) {
       leds[81] = CRGB::Orange;
       leds[80] = CRGB::Orange;
       leds[82] = CRGB::Orange;
        delay(15);
      FastLED.show();
       leds[70] = CRGB::Orange;
       leds[71] = CRGB::Orange;
       leds[72] = CRGB::Orange;
       delay(15);
      FastLED.show();
      leds[73] = CRGB::Orange;
       leds[61] = CRGB::Orange;
       leds[60] = CRGB::Orange;
       leds[59] = CRGB::Orange;
       leds[58] = CRGB::Orange;
       leds[57] = CRGB::Orange;
       delay(15);
      FastLED.show();  
      delay(1500);
      leds[81] = CRGB::Blue;
       leds[80] = CRGB::Blue;
       leds[82] = CRGB::Blue;
        delay(15);
      FastLED.show();
       leds[70] = CRGB::Blue;
       leds[71] = CRGB::Blue;
       leds[72] = CRGB::Blue;
       delay(15);
      FastLED.show();
      leds[73] = CRGB::Blue;
       leds[61] = CRGB::Blue;
       leds[60] = CRGB::Blue;
       leds[59] = CRGB::Blue;
       leds[58] = CRGB::Blue;
       leds[57] = CRGB::Blue;
       delay(1000);
      FastLED.show(); 


      leds[81] = CRGB::Orange;
       leds[80] = CRGB::Orange;
       leds[82] = CRGB::Orange;
        delay(15);
      FastLED.show();
       leds[70] = CRGB::Orange;
       leds[71] = CRGB::Orange;
       leds[72] = CRGB::Orange;
       delay(15);
      FastLED.show();
      leds[73] = CRGB::Orange;
       leds[61] = CRGB::Orange;
       leds[60] = CRGB::Orange;
       leds[59] = CRGB::Orange;
       leds[58] = CRGB::Orange;
       leds[57] = CRGB::Orange;
       delay(15);
      FastLED.show();  
      delay(1500); 
      //Serial.println(numpong[j]);
      //Serial.flush();
      }

    }
 }
