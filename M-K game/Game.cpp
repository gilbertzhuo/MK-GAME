#include "Game.h"
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Computer.h"
using namespace std;


void Game::gamedraw(int size){
    if (moves >= ((size) * ((size)))) {
        cout << "This game is a draw" << endl;
        exit(0);
    }
}


void Game::inputs(int size){
    do {
        if (row < 1) {
            cout << "Please input integer row greater than 1" << endl;
        }
        cout << "What is the row?" << endl;
        cin >> row;
        if (cin.fail() == true) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (row > size || row < 1);
    do {
        if (column < 1) {
            cout << "Please input integer column greater than 1" << endl;
        }
        cout << "What is the column?" << endl;
        cin >> column;
        if (cin.fail() == true) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (column > size|| column < 1);
}


void Game::gamewin(Board& board){
    if (board.gameStatus(row, column, 'O', 0) == WIN) {
        cout << "AWWWWWW YEA!!! Player O won this game!" <<endl;
    }
 else {
        if (board.gameStatus(row, column, 'X',0) == WIN) {
            cout << "AWWWWWW YEA!!! Player X won this game!" << endl;
        }
    }
    exit(0);
}


void Game::move(Board& board){
    if (board.validMove(row, column) == true) {
        p.move(row, column, board);
        moves++;
        if (board.gameStatus(row, column, p.gplayer(), 0) == CONTINUE) {
            c.smart(board);
            moves++;
        }
        board.Displayboard();
    }
}

