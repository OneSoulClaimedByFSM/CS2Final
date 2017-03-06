#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

protected:
    Board *board;
    Side side;
    //Move move;
    int depth = 2;

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    Move *randomMove(std::vector<Move*> moves);
    Move *basicMove(std::vector<Move*> moves);
    Side enemy();
    
    std::tuple<int, Move> Minimax(Board *board, Side side, int depth);
    int position_eval();

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
