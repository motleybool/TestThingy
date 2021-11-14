//- Functions for game builder 
#include "Arduino.h"

//LED Pin Definitions (sparkFunSX1509)
static const uint8_t GB_LED_RED       = 1;
static const uint8_t GB_LED_GREEN     = 0;
static const uint8_t GB_LED_BLUE      = 1; //not working

//Switch Pin Definitions (sparkFunSX1509)
static const uint8_t GB_P1_BLUEvP2_GREEN    = 4;
static const uint8_t GB_P1_BLUEvP2_YELLOW   = 5;
static const uint8_t GB_P1_GREENvP2_BLUE    = 2;
static const uint8_t GB_P1_GREENvP2_YELLOW  = 6;
static const uint8_t GB_P1_YELLOWvP2_BLUE   = 3;
static const uint8_t GB_P1_YELLOWvP2_GREEN  = 7;

//Score Results
#define DRAW     0
#define PLAYER_1 1
#define PLAYER_2 2

//Initialize Routine
void initGameBuilderControls(void);

//Test Routine
void testGameBuilderControls(void);

//Evaluate Game
bool evaluateGameConfig(void);

//Score Round
int scoreRound(int player_1_move, int player_2_move);

//Boot Sequence
void gbBoot(void);

//Reset
void gbReset();

//All On
void gbAllOn(void);

