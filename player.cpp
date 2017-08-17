#include "player.h"

/* private */
/* public */

// Unset min and max Flex while simultaneously setting a new position
void Player::reset(int newPos) {
  dotPosition = newPos;
}

// Given a raw sensor reading (sensorValue), what is the actual "force" that this player is generating?
// Normalized to [0 .. 1]
void Player::setNormalizedForce(int sensorValue) {

  float sensorFloat = float( sensorValue );
  normalizedForce = sensorFloat / 1023;

}

