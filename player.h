#ifndef player_h
#define player_h

#include "Arduino.h"

class Player {
  private:
  public:
     
    float normalizedForce = 0;
    int dotPosition;
    int maxSamples;
    int maxSampleCount;
    
    // constructor
    Player( int dotPos ) : dotPosition( dotPos ) { }

    // Unset min and max Flex while simultaneously setting a new position
    void reset(int newPos);
  
    // Given a raw sensor reading (sensorValue), what is the actual "force" that this player is generating?
    // Normalized to [0 .. 1]
    void setNormalizedForce(int sensorValue);

};

#endif

