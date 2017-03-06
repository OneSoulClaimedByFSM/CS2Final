#include "player.hpp"
#include <cstdlib>
#include <climits>

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */

Player::Player(Side color) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    this->side = color;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) 
{
    this->board->doMove(opponentsMove, enemy());
    while (msLeft == -1 || msLeft > 5)
    {

    }
    return nullptr;
}

int Player::position_eval() {
    //int value = 0;
    /* TODO: wait for name of function
     */
    //std::vector<Move> p_moves;
    
    int black = board->countBlack();
    int white = board->countWhite();
    
    if (this->side == BLACK) return black - white;
    else return white - black;
}

std::tuple<int, Move> *Player::Minimax(Board *board, Side side, int depth) {
    //std::tuple<Move, int> result;
    if (depth == 0) return std::tuple<Move, int> result(position_eval(side), this->move);
    if (depth == this->depth) {
        this->move->x = 0;
        this->move->y = 0;
    }
    std::vector<Move> p_moves = this->board->possibleMoves();
    //std::vector<int> scores;
    int bestValue;
    else if (side == this->side) {
        bestValue = INT_MIN;
        for (int i = 0; i < p_moves.size(); i++) {
            Board *copy = board->copy();
            copy->doMove(&p_moves[i], side);
            int score;
            Move move;
            std::tie(score, move) = Minimax(copy, this->enemy(), depth - 1);
            if (score > bestValue) {
                bestValue = score;
                if (depth == this->depth)
                    this->move = p_moves[i];
            }
        }
        return std::tuple<Move, int> result(bestValue, this->move);
    }
    else {
        bestValue = INT_MAX;
        for (int i = 0; i < p_moves.size(); i++) {
            Board *copy = board->copy();
            copy->doMove(&p_moves[i], side);
            int score;
            Move move;
            std::tie(score, move) = Minimax(copy, this->enemy(), depth - 1);
            if (score < bestValue) {
                bestValue = score;
                if (depth == this->depth)
                    this->move = p_moves[i];
            }
        }
        return std::tuple<Move, int> result(bestValue, this->move);
    }
         
}                    
 
Move *Player::randomMove()
{
    if 
}

Side Player::enemy(){
    if (this->side == WHITE)
        return BLACK;
    return WHITE;
}

