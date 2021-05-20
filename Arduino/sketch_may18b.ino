   #include <FastLED.h>
    #define NUM_LEDS 29
    #define DATA_PIN 6
    CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    String info;
    info = Serial.readStringUntil('\n');
    if(info.equals("1")){
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[2] = CRGB::Green; 
      FastLED.show();
      delay(200);
    }
    else if(info.equals("2")){
      leds[3] = CRGB::Red;
      leds[4] = CRGB::Red;
      leds[5] = CRGB::Red; 
      FastLED.show();
      delay(200);
    }
    else if(info.equals("3")){
      leds[6] = CRGB::Blue;
      leds[7] = CRGB::Blue;
      leds[8] = CRGB::Blue; 
      FastLED.show();
      delay(200);
    }
  }
}
