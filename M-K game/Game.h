#ifndef M_K_V2_GAME_H
#define M_K_V2_GAME_H

#include "Game.h"
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Computer.h"

using namespace std;


class Game {
private:
    int row = 1, column = 1, moves = 0;
public:
    Player p;
    Computer c;

    int grow(){
        return row;
    };

    int gcolumn(){
        return column;
    }

    void gamewin(Board& board);

    void gamedraw(int size);

    void inputs(int size);

    void move(Board& board);
};



#endif //M_K_V2_GAME_H
