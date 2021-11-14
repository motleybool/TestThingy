//- Functions for game controllers 
#include "Arduino.h"

//Switch Pin Definitions
static const uint8_t GC_P1_BLUE    = 25;
static const uint8_t GC_P1_GREEN   = 26;
static const uint8_t GC_P1_YELLOW  = 27;
static const uint8_t GC_P2_BLUE    = 12;
static const uint8_t GC_P2_GREEN   = 13;
static const uint8_t GC_P2_YELLOW  = 14;

#define NO_MOVE     0
#define YELLOW_MOVE 1
#define GREEN_MOVE  2
#define BLUE_MOVE   3

//Initialize Routine
void initGameControllerControls(void);

//Test Routine
void testGameControllerControls(void);

//Player Moves
int getPlayerOneMove(void);
int getPlayerTwoMove(void);

//Controller Functions
bool isPlayerOneBlueSelected(void);
bool isPlayerOneGreenSelected(void);
bool isPlayerOneYellowSelected(void);
bool isPlayerTwoBlueSelected(void);
bool isPlayerTwoGreenSelected(void);
bool isPlayerTwoYellowSelected(void);
