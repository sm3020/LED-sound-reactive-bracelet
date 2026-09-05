#include <Adafruit_NeoPixel.h> 

 

#define MIC_PIN A0 

#define LED_PIN D1 

#define NUM_LEDS 8 

 

#define SAMPLE_WINDOW 30 

#define NOISE_FLOOR 15 

#define SMOOTHING 0.40f 

 

Adafruit_NeoPixel ring( 

  NUM_LEDS, 

  LED_PIN, 

  NEO_GRB + NEO_KHZ800 

); 

 

float smoothedLevel = 0.0f; 

 

void setup() { 

  Serial.begin(115200); 

  analogReadResolution(10); 

 

  pinMode(MIC_PIN, INPUT); 

 

  ring.begin(); 

  ring.setBrightness(80); 

  ring.clear(); 

  ring.show(); 

} 

 

void loop() { 

  unsigned long start = millis(); 

 

  int minVal = 1023; 

  int maxVal = 0; 

 

  while (millis() - start < SAMPLE_WINDOW) { 

    int sample = analogRead(MIC_PIN); 

 

    if (sample > maxVal) { 

      maxVal = sample; 

    } 

 

    if (sample < minVal) { 

      minVal = sample; 

    } 

  } 

 

  int peakToPeak = 

    max(0, (maxVal - minVal) - NOISE_FLOOR); 

 

  smoothedLevel = 

    smoothedLevel * (1.0f - SMOOTHING) + 

    peakToPeak * SMOOTHING; 

 

  // Convert the sound level into eight fixed ranges. 

  int litLEDs = 0; 

 

  if (smoothedLevel > 100) litLEDs = 1; 

  if (smoothedLevel > 200) litLEDs = 2; 

  if (smoothedLevel > 300) litLEDs = 3; 

  if (smoothedLevel > 400) litLEDs = 4; 

  if (smoothedLevel > 500) litLEDs = 5; 

  if (smoothedLevel > 600) litLEDs = 6; 

  if (smoothedLevel > 700) litLEDs = 7; 

  if (smoothedLevel > 800) litLEDs = 8; 

 

  ring.clear(); 

 

  for (int i = 0; i < litLEDs; i++) { 

    float t = (float)i / (NUM_LEDS - 1); 

 

    uint8_t red = 

      (uint8_t)(t * 255); 

 

    uint8_t green = 

      (uint8_t)((1.0f - t) * 200); 

 

    ring.setPixelColor( 

      i, 

      ring.Color(red, green, 0) 

    ); 

  } 

 

  ring.show(); 

 

  Serial.print("Raw:"); 

  Serial.print(peakToPeak); 

 

  Serial.print("\tSmoothed:"); 

  Serial.print(smoothedLevel); 

 

  Serial.print("\tLEDs:"); 

  Serial.println(litLEDs); 

} 

 
