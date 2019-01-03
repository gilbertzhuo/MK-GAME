#include "Computer.h"

void Computer::smart(Board& board) {
    int move =0;
    for (int stepsw = 0; stepsw < board.gstreak();stepsw++) {
        for (int j = 1; j < board.gsize()+1; j++) {
            for (int i =1; i < board.gsize()+1; i++) {
                //Check if computer is 1 move away from winning
                if (board.gstatus(j,i, computer, 0) == true && board.gBoard()[j-1][i-1] == ' ' && move == 0) {
                    board.gBoard()[j-1][i-1] = computer;
                    move++; }
                    // Check if player is 2 steps away from winning
                else if (board.gstatus(j,i, player, 1 ) == true && board.gBoard()[j-1][i-1] == ' ' && move == 0 && board.gstreak() >3 )
                {       board.gBoard()[j-1][i-1] = computer;
                    move++; }
                    // Flow of danger
                else if (board.gBoard()[i - 1][j - 1] == ' ' && move == 0 && board.gstatus(i, j, player, stepsw) == true) {
                    board.gBoard()[i - 1][j - 1] = computer;
                    move++; }
            }
        }
    }
}