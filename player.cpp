#include "player.hpp"
#include <cstdlib>
#include <climits>
#include <tuple>

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */

Player::Player(Side color) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = true;
    this->side = color;
    this->board = new Board();
    this->move = new Move(0,0);

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
    //Move *move = randomMove();
    int score;
    Move *move;
    std::tie(score, move) = Minimax(this->board, this->side, 2);
    this->board->doMove(move, this->side);
    
    // do 
    // {
        
    // } while (msLeft == -1 || elapsed < msLeft);
    return move;
}


int Player::position_eval() {
    
     int black = board->countBlack();
     int white = board->countWhite();
    
     if (this->side == BLACK) return black - white;
     else return white - black;
}

std::tuple<int, Move*> Player::Minimax(Board *board, Side side, int depth) {
    std::tuple<int, Move*> result;
    //std::cerr << depth << std::endl;
    if (depth == 0) {
        std::get<0> (result) = position_eval();
        std::get<1> (result) = this->move;
        return result;
    }
    if (depth == this->depth) {
        this->move->x = 0;
        this->move->y = 0;
    }
    std::vector<Move*> p_moves = board->possibleMoves(side);
    //std::vector<int> scores;
    int bestValue;
    if (side == this->side) {
        bestValue = INT_MIN;
        for (int i = 0; i < p_moves.size(); i++) {
            Board *copy = board->copy();
            copy->doMove(p_moves[i], side);
            int score;
            Move *move;
            std::tie(score, move) = Minimax(copy, this->enemy(), depth - 1);
            if (score > bestValue) {
                bestValue = score;
                if (depth == this->depth)
                    this->move = p_moves[i];
            }
        }
        std::get<0> (result) = bestValue;
        std::get<1> (result) = this->move;
        return result;
    }
    else {
        bestValue = INT_MAX;
        for (int i = 0; i < p_moves.size(); i++) {
            Board *copy = board->copy();
            copy->doMove(p_moves[i], side);
            int score;
            Move *move;
            std::tie(score, move) = Minimax(copy, this->enemy(), depth - 1);
            if (score < bestValue) {
                bestValue = score;
                if (depth == this->depth)
                    this->move = p_moves[i];
            }
        }
        std::get<0> (result) = bestValue;
        std::get<1> (result) = this->move;
        return result;
    }     
}                    



Move *Player::randomMove()
{
    std::vector<Move*> moves = this->board->possibleMoves(this->side);
    if (moves.size() == 0) return nullptr;
    srand(time(NULL));
    int random = rand() % moves.size();
    std::cerr << random << std::endl;
    return moves[random];
}

Side Player::enemy(){
    if (this->side == WHITE)
        return BLACK;
    return WHITE;
}

