#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define LED_COUNT 50

char receivedChar;
boolean newData = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ400);

uint32_t blue = strip.Color(0,0,255);
uint32_t cyan = strip.Color(255,0,255);

uint32_t mid = strip.Color(127,0,255);

/******************************************************/
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
/******************************************************/
void loop() {
  recvOneChar();
  if(receivedChar == 'a') {
    awake();
  }
  if(receivedChar == 'd') {
    done();
  }
  if(receivedChar == 't') {
    thinking();
  }
  if(receivedChar == 's') {
    speaking();
  }
  newData = false;
}

void awake() {
  if(newData)
  {
    //Set first five to cyan
    strip.setPixelColor(0,cyan);
    strip.setPixelColor(1,cyan);
    strip.setPixelColor(2,cyan);
    strip.setPixelColor(3,cyan);
    strip.setPixelColor(4,cyan);
    strip.show();

    //Set new lights to cyan and old to cyan gradually
    for(uint16_t i=5; i<strip.numPixels(); i++)
    {
      strip.setPixelColor(i - 5,blue);
      strip.setPixelColor(i,cyan);
      delay(20);
      strip.show();
    }
  }
}

void thinking() {
  //Set an all blue string
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i,blue);
  }
  //Set an alternating cyan string
  for(uint16_t i=0; i<strip.numPixels(); i+=10)
  {
      for(uint16_t j=0; j<5; j++) {
        strip.setPixelColor(j + i,cyan);
      }
  }
  strip.show();
  delay(200);
  //Set an all cyan string
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i,cyan);
  }
  //Set an alternating blue string
  for(uint16_t i=0; i<strip.numPixels(); i+=10)
  {
      for(uint16_t j=0; j<5; j++) {
        strip.setPixelColor(j + i,blue);
      }
  }
  strip.show();
  delay(200);
}

void speaking() {
  //Set string to fade from blue to cyan
  for(uint16_t c=0; c<256; c++)
  {
    for(uint16_t i=0; i<strip.numPixels(); i++)
    {
      strip.setPixelColor(i,strip.Color(c,0,255));
    }
    strip.show();
    delay(1);
  }
  //Set string to fade from cyan to blue
  for(uint16_t c=0; c<256; c++)
  {
    for(uint16_t i=0; i<strip.numPixels(); i++)
    {
      strip.setPixelColor(i,strip.Color(255 - c,0,255));
    }
    strip.show();
    delay(1);
  }
}

void done() {
   //Set an all black string gradually
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i,strip.Color(0,0,0));
    delay(20);
    strip.show();
  }
}

void recvOneChar() {
 if (Serial.available() > 0) {
   receivedChar = Serial.read();
   newData = true;
 }
}
