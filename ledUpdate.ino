void ledUpdate() {

  int midPixel = (int)targetPixel;

  //begin by blanking all LEDs
  fill_solid( leds, NUM_LEDS, CRGB::Black);

  //draw the "spaceship"
  leds[midPixel-1] = CHSV(HUE_BLUE, 255, 100);
  leds[midPixel] = CHSV(HUE_BLUE, 255, 255);
  leds[midPixel+1] = CHSV(HUE_BLUE, 255, 100);

  //if input is above threshold, draw scaled-length tail
  if( leftPlayer.normalizedForce > 0.05 ) {
    tail( -1, midPixel, leftPlayer.normalizedForce );
  } 
  if( rightPlayer.normalizedForce > 0.05 ) {
    tail( 1, midPixel, rightPlayer.normalizedForce );
  }

  //draw the "mouse" pixel
  uint8_t goalColor = goal.getColor();
  leds[goal.pos] = CRGB(goalColor, goalColor, goalColor);
  
  FastLED.show();
}

void tail (int multiplier, int center, float inputScale) {  //renders thrust tail
  static float tailMax = 12;
  float tailLength = tailMax * inputScale;
  int thisLength = (int)tailLength;
  int fadeValue = 255 / thisLength; // smooth HSV fade to zero

 //increasing frequency and decreasing brightness for tail 
  for( int i=thisLength; i>0; i-- ) {
      int pixelIndex = center+(multiplier*(i+1));
      // clamp for end of row
      pixelIndex = max(pixelIndex, 0);
      pixelIndex = min(pixelIndex, NUM_LEDS-1);
      
      leds[pixelIndex] = CHSV(HUE_ORANGE, 255, 255-(fadeValue*i));
  }
}
