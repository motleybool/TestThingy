//- Functions for game timer 
#include "game_timer.h"
#include "bsp.h"

//Initialize Routine
void initGameTimerControls(void)
{
    //setup leds
    configureLED(GT_3_LED);
    configureLED(GT_2_LED);
    configureLED(GT_1_LED);
    configureLED(GT_WAR_LED);

    //setup switches
    configureButton(GT_PLAY);
    configureButton(GT_RESET);
}

//LED Functions
void gtTurnOn3LED(void) {
    turnOnLED(GT_3_LED);
}
void gtTurnOff3LED(void) {
    turnOffLED(GT_3_LED);
}
void gtTurnOn2LED(void) {
    turnOnLED(GT_2_LED);
}
void gtTurnOff2LED(void) {
    turnOffLED(GT_2_LED);
}
void gtTurnOn1LED(void) {
    turnOnLED(GT_1_LED);
}
void gtTurnOff1LED(void) {
    turnOffLED(GT_1_LED);
}
void gtTurnOnWarLED(void) {
    turnOnLED(GT_WAR_LED);
}
void gtTurnOffWarLED(void) {
    turnOffLED(GT_WAR_LED);
}
void gtBlinkWarLED(int blinks =1) {
    blinkLED(GT_WAR_LED, blinks);
}

//Test Routine
void testGameTimerControls(void)
{
    while(true)
    {
        gtTurnOn3LED();
        delay(250);
        gtTurnOn2LED();
        delay(250);
        gtTurnOn1LED();
        delay(250);
        gtBlinkWarLED(3);
        delay(250);
        gtTurnOnWarLED();
        delay(100);

        if(isPlayButtonPressed()) {
            Serial.println("Play Selected");
        }
        if(isResetButtonPressed()) {
            Serial.println("Reset Selected");
        }
        delay(2000);
        Serial.println("---");

        gtTurnOffWarLED();
        delay(250);
        gtTurnOff1LED();
        delay(250);
        gtTurnOff2LED();
        delay(250);
        gtTurnOff3LED();
        delay(250);
    }
}

//Button Functions
bool isPlayButtonPressed(void) {
    return isButtonPressed(GT_PLAY, true);
}
bool isResetButtonPressed(void) {
    return isButtonPressed(GT_RESET, true);
}

//Play Countdown
void animatePlayCountdown(void)
{
    gtReset();
    gtTurnOn3LED();
    delay(1500);
    gtTurnOn2LED();
    delay(1500);
    gtTurnOn1LED();
    delay(1500);
    gtBlinkWarLED(2);
    gtTurnOnWarLED();
}

//Boot Sequence
void gtBoot(void)
{
        gtTurnOn3LED();
        delay(250);
        gtTurnOn2LED();
        delay(250);
        gtTurnOn1LED();
        delay(250);
        gtBlinkWarLED(3);
        delay(250);
        gtTurnOnWarLED();
        
        delay(1000);

        gtTurnOffWarLED();
        delay(250);
        gtTurnOff1LED();
        delay(250);
        gtTurnOff2LED();
        delay(250);
        gtTurnOff3LED();
        delay(250);

        gtReset();
}

//Reset
void gtReset(void) 
{
    gtTurnOffWarLED();
    gtTurnOff1LED();
    gtTurnOff2LED();
    gtTurnOff3LED();
}

//All On
void gtAllOn(void)
{
    gtTurnOn3LED();
    gtTurnOn2LED();
    gtTurnOn1LED();
    gtTurnOnWarLED();
}