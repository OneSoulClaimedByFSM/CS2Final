#include <climits>
#include <iostream>
#ifndef __COMMON_H__
#define __COMMON_H__

enum Side { 
    WHITE, BLACK
};

class Move {
   
public:
    int x, y;
    Move(int x, int y) {
        this->x = x;
        this->y = y;       

    }
    ~Move() {}
    
    void operator = (const Move &move) {
        this->x = move.x;
        this->y = move.y;
    }

    int getX() { return x; }
    int getY() { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    
    void print() {
        std::cerr << "(" << this->x << ", " << this->y << ")" << std::endl;
    }
    
};

#endif
