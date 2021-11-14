//- Functions for game score 
#include "game_score.h"
#include "bsp.h"

//Initialize Routine
void initGameScoreControls(void)
{
    //setup leds
    configureLED(GS_P1_ROUND);
    configureLED(GS_P2_ROUND);
    configureLED(GS_P1_PT_1);
    configureLED(GS_P1_PT_2);
    configureLED(GS_P2_PT_1);
    configureLED(GS_P2_PT_2);
}

//LED Functions
void gsTurnOnP1RoundLED(void) {
    turnOnLED(GS_P1_ROUND);
}
void gsTurnOffP1RoundLED(void) {
    turnOffLED(GS_P1_ROUND);
}
void gsBlinkP1RoundLED(int blinks) {
    blinkLED(GS_P1_ROUND, blinks);
}
void gsTurnOnP2RoundLED(void) {
    turnOnLED(GS_P2_ROUND);
}
void gsTurnOffP2RoundLED(void) {
    turnOffLED(GS_P2_ROUND);
}
void gsBlinkP2RoundLED(int blinks) {
    blinkLED(GS_P2_ROUND, blinks);
}
void gsTurnOnP1PT1LED(void) {
    turnOnLED(GS_P1_PT_1);
}
void gsTurnOffP1PT1LED(void) {
    turnOffLED(GS_P1_PT_1);
}
void gsTurnOnP1PT2LED(void) {
    turnOnLED(GS_P1_PT_2);
}
void gsTurnOffP1PT2LED(void) {
    turnOffLED(GS_P1_PT_2);
}
void gsTurnOnP2PT1LED(void) {
    turnOnLED(GS_P2_PT_1);
}
void gsTurnOffP2PT1LED(void) {
    turnOffLED(GS_P2_PT_1);
}
void gsTurnOnP2PT2LED(void) {
    turnOnLED(GS_P2_PT_2);
}
void gsTurnOffP2PT2LED(void) {
    turnOffLED(GS_P2_PT_2);
}

//Test Routine
void testGameScoreControls(void)
{
    while(true)
    {
        gsBlinkP1RoundLED(2);
        gsTurnOnP1RoundLED();
        delay(250);
        gsTurnOnP1PT1LED();
        delay(250);

        gsBlinkP2RoundLED(2);
        gsTurnOnP2RoundLED();
        delay(250);
        gsTurnOnP2PT1LED();
        delay(250);

        gsBlinkP1RoundLED(2);
        gsTurnOnP1RoundLED();
        delay(250);
        gsTurnOnP1PT2LED();
        delay(250);

        gsBlinkP2RoundLED(2);
        gsTurnOnP2RoundLED();
        delay(250);
        gsTurnOnP2PT2LED();
        delay(250);

        clearPlayerOne();
        delay(250);
        clearPlayerTwo();
        delay(250);
    }
}

//Update Score
void updateScore(Score score)
{
    if(score.player1_win)
    {
        gsBlinkP1RoundLED(3);
        if(score.player1_score > 0) {
            gsTurnOnP1PT1LED();
        }
        if(score.player1_score > 1) {
            gsTurnOnP1PT2LED();
        }
    }
    
    if(score.player2_win)
    {
        gsBlinkP2RoundLED(3);
        if(score.player2_score > 0) {
            gsTurnOnP2PT1LED();
        }
        if(score.player2_score > 1) {
            gsTurnOnP2PT2LED();
        }
    }
}

//Animate Win
void animatePlayerWin(Score score)
{
    if(score.player1_score >= 2)
    {
        for(int i=0; i<4; i++) {
            gsTurnOnP1RoundLED();
            gsTurnOnP1PT1LED();
            gsTurnOnP1PT2LED();
            delay(250);
            gsTurnOffP1RoundLED();
            gsTurnOffP1PT1LED();
            gsTurnOffP1PT2LED();
            delay(250);
            gsTurnOnP1RoundLED();
            gsTurnOnP1PT1LED();
            gsTurnOnP1PT2LED();
        }
    }
    if(score.player2_score >= 2)
    {
        for(int i=0; i<4; i++) {
            gsTurnOnP2RoundLED();
            gsTurnOnP2PT1LED();
            gsTurnOnP2PT2LED();
            delay(250);
            gsTurnOffP2RoundLED();
            gsTurnOffP2PT1LED();
            gsTurnOffP2PT2LED();
            delay(250);
            gsTurnOnP2RoundLED();
            gsTurnOnP2PT1LED();
            gsTurnOnP2PT2LED();
        }
    }
}

//Error/Draw Animation
void displayErrorDraw(void)
{
    for(int i=0; i<2; i++)
    {
        gsTurnOnP1RoundLED();
        gsTurnOnP2RoundLED();
        delay(250);
        gsTurnOffP1RoundLED();
        gsTurnOffP2RoundLED();
        delay(250);
    }
}

//Boot Sequence
void gsBoot(void)
{
        gsBlinkP1RoundLED(2);
        gsTurnOnP1RoundLED();
        delay(50);
        gsTurnOnP1PT1LED();
        delay(50);

        gsBlinkP2RoundLED(2);
        gsTurnOnP2RoundLED();
        delay(50);
        gsTurnOnP2PT1LED();
        delay(50);

        gsBlinkP1RoundLED(2);
        gsTurnOnP1RoundLED();
        delay(50);
        gsTurnOnP1PT2LED();
        delay(50);

        gsBlinkP2RoundLED(2);
        gsTurnOnP2RoundLED();
        delay(50);
        gsTurnOnP2PT2LED();
        delay(50);

        gsReset();
}

//Reset
void gsReset(void) {
    clearPlayerOne();
    clearPlayerTwo();
}
void clearPlayerOne(void) {
    gsTurnOffP1RoundLED();
    gsTurnOffP1PT1LED();
    gsTurnOffP1PT2LED();
}
void clearPlayerTwo(void) {
    gsTurnOffP2RoundLED();
    gsTurnOffP2PT1LED();
    gsTurnOffP2PT2LED();
}

//All On
void gsAllOn(void)
{
    gsTurnOnP1RoundLED();
    gsTurnOnP1PT1LED();
    gsTurnOnP1PT2LED();
    gsTurnOnP2RoundLED();
    gsTurnOnP2PT1LED();
    gsTurnOnP2PT2LED();
}