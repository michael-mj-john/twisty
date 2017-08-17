#include "FastLED.h"
#include "player.h"
#include "goal.h"

#define NUM_LEDS 144
#define DATA_PIN 7
#define LEFT_PLAYER_PIN A0
#define RIGHT_PLAYER_PIN A1
#define TARGET_FRAMES 5
#define GOAL_TIME 200

CRGB leds[NUM_LEDS];

double targetPixel;
long lastDrawMillis;
int frameCount;
int points=0;

enum gameStates { start, play, win };
gameStates gameState;

double velocity;
static double thrustMax = 4;

uint16_t framesAtTarget;
//int goalPixel;
Goal goal(0, GOAL_TIME);

Player leftPlayer(NUM_LEDS/2 - 1);
Player rightPlayer(NUM_LEDS/2 + 1);

int leftSensorRead;
int rightSensorRead;
