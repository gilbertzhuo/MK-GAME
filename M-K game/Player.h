#ifndef M_K_V2_PLAYER_H
#define M_K_V2_PLAYER_H


#include "Board.h"



class Player {
protected:
    char player = 'X';
    char computer = 'O';
public:
    void move(int row, int column, Board& board);

    int gplayer(){
        return player;
    }

    int gcomputer(){
        return computer;
    }

};


#endif //M_K_V2_PLAYER_H
