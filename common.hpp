#include <climits>
#include <iostream>
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
        setScore();      

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
    void setScore() {
        bool edgeX = (x == 0 || x == 7);
        bool edgeY = (y == 0 || y == 7);
        bool edgeT = false;
        if (edgeX && edgeY)
            this->score = 10;

        if ((edgeX && y >= 2 && y <= 5) || (edgeY && x >= 2 && x <= 5))
        {
            this->score = 5;
            edgeT = true;
        }
        else if (!edgeT && !edgeX && !edgeY && !((x == 1 || x == 6) && (y ==1 || y == 6)))
        {
            this->score = 1;
        }
        
        else if ((x == 1 || x == 6) && (y ==1 || y == 6))
            this->score = 1;
        else if ((edgeX && (y == 1 || y == 6)) || (edgeY && (x == 1 || x == 6)))
            this->score = 1;
    }
    
    void print() {
        std::cerr << "(" << this->x << ", " << this->y << ")" << std::endl;
    }
    
};

#endif
