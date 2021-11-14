//- Functions for game score 
#include "Arduino.h"

//LED Pin Definitions
static const uint8_t GS_P1_ROUND   = 15;
static const uint8_t GS_P2_ROUND   = 2;
static const uint8_t GS_P1_PT_1    = 0;
static const uint8_t GS_P1_PT_2    = 4;
static const uint8_t GS_P2_PT_1    = 5;//17;
static const uint8_t GS_P2_PT_2    = 16;

struct Score {
    int player1_score;
    int player1_move;
    bool player1_win;
    int player2_score;
    int player2_move;
    bool player2_win;
};

//Initialize Routine
void initGameScoreControls(void);

//Test Routine
void testGameScoreControls(void);

//Update Score
void updateScore(Score score);

//Animate Win
void animatePlayerWin(Score score);

//Error/Draw Animation
void displayErrorDraw(void);

//Boot Sequence
void gsBoot(void);

//Reset
void gsReset(void);
void clearPlayerOne(void);
void clearPlayerTwo(void);

//All On
void gsAllOn(void);