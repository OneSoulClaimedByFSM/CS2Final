#ifndef __BOARD_H__
#define __BOARD_H__

#include <bitset>
#include <vector>
#include "common.hpp"
using namespace std;

class Board {

private:
    bitset<64> black;
    bitset<64> taken;
    int score[8][8] = { {100, -8, 8, 6, 6, 8, -8, 100},
                        {-8, -24, -4, 1, 1, -4, -24, -8},
                        {8, -4, 7, 4, 4, 7, -4, 8},
                        {6, 1, 4, 0, 0, 4, 1, 6},
                        {6, 1, 4, 0, 0, 4, 1, 6},
                        {8, -4, 7, 4, 4, 7, -4, 8},
                        {-8, -24, -4, 1, 1, -4, -24, -8},
                        {100, -8, 8, 6, 6, 8, -8, 100} };

    bool occupied(int x, int y);
    bool get(Side side, int x, int y);
    void set(Side side, int x, int y);
    bool onBoard(int x, int y);

public:
    Board();
    ~Board();
    Board *copy();

    bool isDone();
    bool hasMoves(Side side);
    bool checkMove(Move *m, Side side);
    void doMove(Move *m, Side side);
    int count(Side side);
    int countBlack();
    int countWhite();
    std::vector<Move*> possibleMoves(Side side);
    int mobility(Side side);
    int state(Side side);
    int frontier(Side side);

    void setBoard(char data[]);
};

#endif
