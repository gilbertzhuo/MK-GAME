#include <iostream>

using namespace std;

#include "Board.h"
#include "Player.h"
#include "Game.h"


int main() {
    Board b;
    Player p;
    Game g;


    do {

        g.inputs(b.gsize());
        g.move(b);
        g.gamedraw(b.gsize());

    } while (b.gameStatus(g.grow(), g.gcolumn(), p.gcomputer(), 0) != WIN &&
             b.gameStatus(g.grow(), g.gcolumn(), p.gplayer(), 0) != WIN);

    g.gamewin(b);




}
