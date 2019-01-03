#ifndef M_K_V2_BOARD_H
#define M_K_V2_BOARD_H

using namespace std;
#include <string>

enum status {WIN, CONTINUE};
class Board {

private:
    char **board;
    int streak = 3,size;
public:
    Board();
    ~Board();
    void Displayboard();
    bool validMove(int row, int column);
    status gameStatus(int row, int column, char symbol, int check);
    bool gstatus(int row, int column, char symbol, int check);
    char ** gBoard()
    {
        return board;
    }

    int gstreak(){
        return streak;
    }

    int gsize(){
        return size;
    }

};


#endif //M_K_V2_BOARD_H
