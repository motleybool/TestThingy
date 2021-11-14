//- Functions for game builder 
#include "game_builder.h"
#include "game_controllers.h"
#include "bsp.h"
#include <Wire.h>
#include <sparkFunSX1509.h> // Include SX1509 library

//SX1509 GPIO Expander Opbject
SX1509 io;

//Initialize Routine
void initGameBuilderControls(void)
{
    // Call io.begin(<I2C address>) to initialize the I/O
    // expander. It'll return 1 on success, 0 on fail.
    if (!io.begin(0x3E))
    {
        // If we failed to communicate, turn the pin 13 LED on
        Serial.println("Error initializing expander");
        while (1)
        ; // And loop forever.
    }

    //setup leds
    io.pinMode(GB_LED_RED, OUTPUT);
    io.pinMode(GB_LED_GREEN, OUTPUT);

    //setup switches
    io.pinMode(GB_P1_BLUEvP2_GREEN, INPUT_PULLUP);
    io.pinMode(GB_P1_BLUEvP2_YELLOW, INPUT_PULLUP);
    io.pinMode(GB_P1_GREENvP2_BLUE, INPUT_PULLUP);
    io.pinMode(GB_P1_GREENvP2_YELLOW, INPUT_PULLUP);
    io.pinMode(GB_P1_YELLOWvP2_BLUE, INPUT_PULLUP);
    io.pinMode(GB_P1_YELLOWvP2_GREEN, INPUT_PULLUP);
}

//LED Functions
void gbTurnOnRedLED(void) {
    io.digitalWrite(GB_LED_RED, LOW);
}
void gbTurnOffRedLED(void) {
    io.digitalWrite(GB_LED_RED, HIGH);
}
void gbBlinkRedLED(int blinks = 1) {
    for(int i=0; i < blinks; i++){
        gbTurnOnRedLED();
        delay(100);
        gbTurnOffRedLED();
        delay(100);
    }
}
void gbTurnOnGreenLED(void) {
    io.digitalWrite(GB_LED_GREEN, LOW);
}
void gbTurnOffGreenLED(void) {
    io.digitalWrite(GB_LED_GREEN, HIGH);
}
void gbBlinkGreenLED(int blinks = 1) {
    for(int i=0; i < blinks; i++){
        gbTurnOnGreenLED();
        delay(100);
        gbTurnOffGreenLED();
        delay(100);
    }
}

//Switch Functions
bool doesBlueBeatGreen(void) {
    return (io.digitalRead(GB_P1_BLUEvP2_GREEN) == HIGH);
}
bool doesBlueBeatYellow(void) {
    return (io.digitalRead(GB_P1_BLUEvP2_YELLOW) == HIGH);
}
bool doesGreenBeatBlue(void) {
    return (io.digitalRead(GB_P1_GREENvP2_BLUE) == HIGH);
}
bool doesGreenBeatYellow(void) {
    return (io.digitalRead(GB_P1_GREENvP2_YELLOW) == HIGH);
}
bool doesYellowBeatBlue(void) {
    return (io.digitalRead(GB_P1_YELLOWvP2_BLUE) == HIGH);
}
bool doesYellowBeatGreen(void) {
    return (io.digitalRead(GB_P1_YELLOWvP2_GREEN) == HIGH);
}

//Test Routine
void testGameBuilderControls(void)
{
    while(true)
    {
        // gbTurnOnRedLED();
        // delay(250);
        // gbTurnOffRedLED();
        // delay(100);
        // gbTurnOnGreenLED();
        // delay(250);
        // gbTurnOffGreenLED();
        // delay(100);

        if(doesBlueBeatGreen()) 
            Serial.println("Blue Beats Green");
        if(doesBlueBeatYellow())
            Serial.println("Blue Beats Yellow");
        if(doesGreenBeatBlue())
            Serial.println("Green Beats Blue");
        if(doesGreenBeatYellow())
            Serial.println("Green Beats Yellow");
        if(doesYellowBeatBlue())
            Serial.println("Yellow Beats Blue");
        if(doesYellowBeatGreen())
            Serial.println("Yellow Beats Green");
        delay(2000);
        Serial.println("---");

        //evaluate game settings
        evaluateGameConfig();
        Serial.println("---");
    }
}

//Evaluate Game
bool evaluateGameConfig(void)
{
    //Check Player One Blue
    if((doesBlueBeatGreen() && doesBlueBeatYellow()) ||
       (!doesBlueBeatGreen() && !doesBlueBeatYellow()))
    {
        gbTurnOffGreenLED();
        gbTurnOnRedLED();
        //Serial.println("Game Config Invalid");
        return false;
    } 
    //Check Player Two Blue
    if((doesGreenBeatBlue() && doesYellowBeatBlue()) ||
       (!doesGreenBeatBlue() && !doesYellowBeatBlue()))
    {
        gbTurnOffGreenLED();
        gbTurnOnRedLED();
        //Serial.println("Game Config Invalid");
        return false;
    }  

    //Check Player One Green
    if((doesGreenBeatBlue() && doesGreenBeatYellow()) ||
       (!doesGreenBeatBlue() && !doesGreenBeatYellow()))
    {
        gbTurnOffGreenLED();
        gbTurnOnRedLED();
        //Serial.println("Game Config Invalid");
        return false;
    }  
    //Check Player Two Green
    if((doesBlueBeatGreen() && doesYellowBeatGreen()) ||
       (!doesBlueBeatGreen() && !doesYellowBeatGreen()))
    {
        gbTurnOffGreenLED();
        gbTurnOnRedLED();
        //Serial.println("Game Config Invalid");
        return false;
    }  

    //Check Player One Yellow
    if((doesYellowBeatBlue() && doesYellowBeatGreen()) ||
       (!doesYellowBeatBlue() && !doesYellowBeatGreen()))
    {
        gbTurnOffGreenLED();
        gbTurnOnRedLED();
        //Serial.println("Game Config Invalid");
        return false;
    }
    //Check Player Two Yellow
    if((doesBlueBeatYellow() && doesGreenBeatYellow()) ||
       (!doesBlueBeatYellow() && !doesGreenBeatYellow()))
    {
        gbTurnOffGreenLED();
        gbTurnOnRedLED();
        //Serial.println("Game Config Invalid");
        return false;
    }    
    
    gbTurnOffRedLED();
    gbTurnOnGreenLED();
    //Serial.println("Game Config Valid");
    return true;
}

//Score Round
int scoreRound(int player_1_move, int player_2_move)
{
    Serial.printf("Player 1: %d, Player 2: %d\n", player_1_move, player_2_move);
    
    //Check Draw Scenarios
    if(player_1_move == player_2_move)
    {
        return DRAW;
    }

    //Check Player One Blues
    if(player_1_move == BLUE_MOVE)
    {
        //Check Player Two Move
        if(player_2_move == GREEN_MOVE)
        {
            return doesBlueBeatGreen() ? PLAYER_1 : PLAYER_2;
        } 
        else if (player_2_move == YELLOW_MOVE)
        {
            return doesBlueBeatYellow() ? PLAYER_1 : PLAYER_2;
        }
    }

    //Check Player One Greens
    if(player_1_move == GREEN_MOVE)
    {
        //Check Player Two Move
        if(player_2_move == BLUE_MOVE)
        {
            return doesGreenBeatBlue() ? PLAYER_1 : PLAYER_2;
        } 
        else if (player_2_move == YELLOW_MOVE)
        {
            return doesGreenBeatYellow() ? PLAYER_1 : PLAYER_2;
        }
    }

    //Check Player One Yellows
    if(player_1_move == YELLOW_MOVE)
    {
        //Check Player Two Move
        if(player_2_move == BLUE_MOVE)
        {
            return doesYellowBeatBlue() ? PLAYER_1 : PLAYER_2;
        } 
        else if (player_2_move == GREEN_MOVE)
        {
            return doesYellowBeatGreen() ? PLAYER_1 : PLAYER_2;
        }
    }

    //never reach
    Serial.println("Error Draw");
    return PLAYER_2;
}

//Boot Sequence
void gbBoot(void)
{
    gbBlinkGreenLED(3);
    delay(100);
    gbBlinkGreenLED(2);
    gbTurnOnGreenLED();
}

//Reset
void gbReset()
{
    gbTurnOffRedLED();
    gbTurnOffGreenLED();
}

//All On
void gbAllOn(void)
{
    gbTurnOnGreenLED();
    gbTurnOnRedLED();
}

