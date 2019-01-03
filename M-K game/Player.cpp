#include <iostream>z
#include "Player.h"
#include "Board.h"

void Player::move(int row, int column, Board& board) {
    board.gBoard()[row-1][column-1] = player;
}



