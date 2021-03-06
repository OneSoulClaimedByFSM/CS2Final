#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

protected:
    Side side;
    Move *move;
    int depth = 4;
    int alpha[2] = {0,0};
    int beta[2] = {0,0};
    
public:
    Board *board;
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    Move *randomMove();
    Move *basicMove(std::vector<Move*> moves);
    Side enemy();
    
    std::tuple<double, Move*> Minimax(Board *board, Side side, int depth);
    double evaluate(double mine, double enem);
    double position_eval(Board *board);
    double endgame_eval(Board *board);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
