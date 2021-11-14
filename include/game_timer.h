//- Functions for game timer 
#include "Arduino.h"

//LED Pin Definitions
static const uint8_t GT_3_LED    = 3;
static const uint8_t GT_2_LED    = 19;
static const uint8_t GT_1_LED    = 23;
static const uint8_t GT_WAR_LED  = 18;

//Switch Pin Definitions
static const uint8_t GT_PLAY    = 32;
static const uint8_t GT_RESET   = 33;


//Initialize Routine
void initGameTimerControls(void);

//Test Routine
void testGameTimerControls(void);

//Button Functions
bool isPlayButtonPressed(void);
bool isResetButtonPressed(void);

//Play Countdown
void animatePlayCountdown(void);

//Boot Sequence
void gtBoot(void);

//Reset
void gtReset(void);

//All On
void gtAllOn(void);