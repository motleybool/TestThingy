//- Functions for game controllers 
#include "game_controllers.h"
#include "bsp.h"

//Initialize Routine
void initGameControllerControls(void)
{
    //setup switches
    configureButton(GC_P1_BLUE);
    configureButton(GC_P1_GREEN);
    configureButton(GC_P1_YELLOW);
    configureButton(GC_P2_BLUE);
    configureButton(GC_P2_GREEN);
    configureButton(GC_P2_YELLOW);
}

//Test Routine
void testGameControllerControls(void)
{
    while(true)
    {
        if(isPlayerOneBlueSelected()) 
            Serial.println("Player One Blue");
        if(isPlayerOneGreenSelected())
            Serial.println("Player One Green");
        if(isPlayerOneYellowSelected())
            Serial.println("Player One Yellow");
        if(isPlayerTwoBlueSelected())
            Serial.println("Player Two Blue");
        if(isPlayerTwoGreenSelected())
            Serial.println("Player Two Green");
        if(isPlayerTwoYellowSelected())
            Serial.println("Player Two Yellow");
        delay(2000);
        Serial.println("---");
    }
}

//Player Moves
int getPlayerOneMove(void)
{
    int num = 0;
    int move = NO_MOVE;
    if(isPlayerOneYellowSelected()) {
        num++;
        move = YELLOW_MOVE;
    }
    if(isPlayerOneGreenSelected()) {
        num++;
        move = GREEN_MOVE;
    }
    if(isPlayerOneBlueSelected()) {
        num++;
        move = BLUE_MOVE;
    }

    if(num != 1) {
        Serial.println("Player One Cheated...");
        move = NO_MOVE;
    }
    return move;
}
int getPlayerTwoMove(void)
{
    int num = 0;
    int move = NO_MOVE;
    if(isPlayerTwoYellowSelected()) {
        num++;
        move = YELLOW_MOVE;
    }
    if(isPlayerTwoGreenSelected()) {
        num++;
        move = GREEN_MOVE;
    }
    if(isPlayerTwoBlueSelected()) {
        num++;
        move = BLUE_MOVE;
    }

    if(num != 1) {
        Serial.println("Player Two Cheated...");
        move = NO_MOVE;
    }

    return move;
}

//Controller Functions
bool isPlayerOneBlueSelected(void) {
    return isButtonPressed(GC_P1_BLUE, true);
}
bool isPlayerOneGreenSelected(void) {
    return isButtonPressed(GC_P1_GREEN, true);
}
bool isPlayerOneYellowSelected(void) {
    return isButtonPressed(GC_P1_YELLOW, true);
}
bool isPlayerTwoBlueSelected(void) {
    return isButtonPressed(GC_P2_BLUE, true);
}
bool isPlayerTwoGreenSelected(void) {
    return isButtonPressed(GC_P2_GREEN, true);
}
bool isPlayerTwoYellowSelected(void) {
    return isButtonPressed(GC_P2_YELLOW, true);
}