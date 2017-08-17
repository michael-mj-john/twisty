#include "twisty.h"

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_PLAYER_PIN,INPUT);
  pinMode(RIGHT_PLAYER_PIN, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(A0));
  frameCount = 0;
  gameState = start;
}

void loop() {

  switch (gameState) {
    case start:
      gameStart();
      break;     
    case win:
      pointScored();
      break;      
    case play:
      if (millis() > lastDrawMillis + 1000/30) { // 30 fps LED update
        frameCount < 30 ? frameCount++ : frameCount = 0;
        gameUpdate();
        lastDrawMillis = millis();
      }
      break;     
    default:
      break;
  }
}


void gameStart(void) {
  velocity = 0;
  gameState = play;
  leftPlayer.reset(NUM_LEDS/2 - 1);
  rightPlayer.reset(NUM_LEDS/2 + 1);

  // Configure goal (but don't show it yet!)
  goal.reset(NUM_LEDS, points, GOAL_TIME);

  // Draw target
  targetPixel = NUM_LEDS/2;
  leds[(int)targetPixel] = CHSV(HUE_BLUE, 255, 255);
  FastLED.show();

  Serial.println("game start complete");
}

void pointScored( void ) {

  points++;
  for( int j=0; j<points; j++ ) {
    for( int i =0; i<NUM_LEDS; i++ ) {
      leds[i] = CHSV(HUE_GREEN, 255, 100);
    }
    FastLED.show();
    delay(300);
    
    clearDisplay();

    Serial.println( "point scored!" );
    delay(300);
  }
  
  gameState = start;
  
}

// Turn off all LEDS
void clearDisplay() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

