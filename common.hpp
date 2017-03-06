#include <climits>
#ifndef __COMMON_H__
#define __COMMON_H__

enum Side { 
    WHITE, BLACK
};

class Move {
   
public:
    int x, y, score;
    Move(int x, int y) {
        this->x = x;
        this->y = y; 
        this->score = INT_MIN;       
    }
    ~Move() {}

    int getX() { return x; }
    int getY() { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};

#endif
