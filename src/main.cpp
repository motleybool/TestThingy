/**
 * 3-2-1 War!
 *
 * Fun game to play
 */
#include "Arduino.h"
#include "bsp.h"
#include "game_builder.h"
#include "game_timer.h"
#include "game_score.h"
#include "game_controllers.h"


//heartbeat function for builtin LED
void heartbeat(void) {
    //blinkLED(LED_BUILTIN, 2);
}

//Game Data
Score score;

void clearScore(void) 
{
    score.player1_score = 0;
    score.player1_move = NO_MOVE;
    score.player1_win = false;
    score.player2_score = 0;
    score.player2_move = NO_MOVE;
    score.player2_win = false;
    gtReset();
    gsReset();
}

bool scoreRound(void)
{
    score.player1_win = false;
    score.player2_win = false;

    //check cheats
    if((score.player1_move == NO_MOVE) && (score.player2_move == NO_MOVE)) {
        Serial.println("Both Cheated...");
        return false;
    }
    else if((score.player1_move == NO_MOVE) && (score.player2_move != NO_MOVE)) {
        Serial.println("Player Two Wins...");
        score.player2_score++;
        score.player2_win = true;
        return true;
    }
    else if((score.player1_move != NO_MOVE) && (score.player2_move == NO_MOVE)) {
        Serial.println("Player One Wins...");
        score.player1_score++;
        score.player1_win = true;
        return true;
    }

    //score round
    int round = scoreRound(score.player1_move, score.player2_move);

    if(round == DRAW) {
        Serial.println("Draw...");
        return false;
    }
    else if(round == PLAYER_1) {
        Serial.println("Player One Wins...");
        score.player1_score++;
        score.player1_win = true;
        return true;
    }
    else if(round == PLAYER_2) {
        Serial.println("Player Two Wins...");
        score.player2_score++;
        score.player2_win = true;
        return true;
    }


    //should never reach
    return false;
}

void setup()
{
    // configure serial port
    Serial.begin(9600);

    // configure heartbeat
    //configureLED(LED_BUILTIN);

    // configure game builder
    initGameBuilderControls();

    // configure game timer
    initGameTimerControls();

    // configure game score
    initGameScoreControls();

    // configure game controllers
    initGameControllerControls();

    //reset
    gsReset();
    gtReset();
    gbReset();

    //boot
    gbBoot();
    gtBoot();
    gsBoot();
}

void runTestSuite(void)
{
    // run game timer tests
    //testGameTimerControls();

    // run game score tests
    //testGameScoreControls();

    // run game controller tests
    //testGameControllerControls();

    // run game builder tests
    //testGameBuilderControls();
}

void loop()
{
    // run heartbeat
    heartbeat();

    // test leds
    // gsAllOn();
    // gbAllOn();
    // gtAllOn();

    //Evaluate Game Config
    evaluateGameConfig();

    //Run Test Suite
    //runTestSuite();

    //Check Reset
    if(isResetButtonPressed())
    {
        Serial.println("Clearing Scores...");
        clearScore();
        gtReset();
    }

    //Check Play
    if(isPlayButtonPressed())
    {
        Serial.println("Play Round...");

        //Timer Animation
        animatePlayCountdown();

        //Capture Moves
        score.player1_move = getPlayerOneMove();
        score.player2_move = getPlayerTwoMove();

        //Score Round
        if(scoreRound())
        {
            //Update Scores
            updateScore(score);

            //Score Game
            animatePlayerWin(score);
        }
        else {
            //Show Draw/Cheat
            displayErrorDraw();
        }
    }
}

