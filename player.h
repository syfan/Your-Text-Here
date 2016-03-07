#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
using namespace std;

class Player {

private:
    Board *board;

public:
    Player(Side side);
    ~Player();
    
    Move *doMove(Move *opponentsMove, int msLeft);

    Side side; // to keep track of side
    Side opponentSide;

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
