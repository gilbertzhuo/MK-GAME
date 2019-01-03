#include <cerrno>
#include <iostream>
#include "Board.h"
#include <iomanip>

using namespace std;


void Board::Displayboard() {
    cout << endl;
    cout << "     ";

    for (int i = 1; i <= size; i++) {
        cout << i << setw(11);
    }
    cout << "\n" << endl;
    for (int i = 0; i < size; i++) {
        cout << "===========";
    }
    cout << endl;
    for (int j = 0; j < size; j++) {

        for (int k = 0; k < 3; k++) {

            for (int i = 0; i < size; i++) {
                if (k != 1)
                    cout << "=         =";
                if (k == 1 && i != size - 1)
                    cout << "=    " << board[j][i] << "    =";

                if (k == 1 && i == size - 1) {
                    cout << "=    " << board[j][i] << "    =" << "    " << j + 1;
                }


            }
            cout << endl;
        }

        for (int i = 0; i < size; i++)
            cout << "===========";
        cout << endl;

    }


}


bool Board::validMove(int row, int column)  {
    if (board[row-1][column-1] == ' ') {
        return true;
    } else {
        return false;
    }
}

Board::Board() {
    // Get board size
    do {
        cout << "What is the size of the board?(LIMIT:10)" << endl;
        cin >> size;
    } while (size > 10);

    board = new char* [size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
    }

    // Initialize board to empty
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            board[j][i] = ' ';
        }
    };
    do {
        if(streak < 3)
        {
            cout<<"Please make your streak greater than 2."<<endl;
        }
        cout << "Streak number?(NOT MORE THAN SIZE)" << endl;
        do {
            if(size >3 && streak <=3)
            {
                cout<<"ADDITIONAL RULE: Make streak greater than 3 " <<endl;
            }
            cin >> streak;
            if (cin.fail() == true) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(size>3 && streak <=3);
    } while (streak > size || streak < 3);

    Board::Displayboard();
}

      status Board::gameStatus(int row, int column, char symbol, int check) {
          int count = 0, ncount = 0, xcount = 0;

          //Check Horizontal
          for (int i = 0; i <= streak; i++) {

              if(size >= (column - 1 + i)) {
                  if (board[row - 1][column - 1 + i] == symbol && ncount == 0) {
                      count++;
                  } else {
                      ncount++;
                  }
              }

              if (column - 1 - i >= 0) {
                  if (board[row - 1][column - 1 - i] == symbol && xcount == 0) {
                      count++;
                  } else {
                      xcount++;
                  }
              }

          }
          if (count+check > streak) {
              return WIN;
          }

          count = 0,ncount = 0, xcount =0;

          // Check Vertical
          for (int i = 0; i < streak; i++) {
              if(size > (row - 1 + i)) {
                  if (board[row - 1 + i][column - 1] == symbol && ncount == 0) {
                      count++;
                  } else {
                      ncount++;
                  }
              }
              if (row - 1 - i >= 0) {
                  if (board[row - 1 - i][column - 1] == symbol && xcount == 0) {
                      count++;
                  } else {
                      xcount++;
                  }
              }
              if (count+ check > streak) {
                  return WIN;
              }
          }

          count = 0,ncount = 0, xcount =0;

          //Check Diagonal "\"
          for (int i = 0; i <= streak; i++)
          {
              if(size > (row - 1 + i) && size > (column - 1 + i)) {
                  if (board[row-1 + i][column-1 + i] == symbol && ncount == 0) {
                      count++;
                  } else {
                      ncount++;
                  }
              }

              if(row - 1 - i >= 0 && column - 1 - i >= 0){
                  if (board[row-1 - i][column-1 - i] == symbol  && xcount == 0) {
                      count++;
                  } else {
                      xcount++;
                  }
              }

          }
          if(check+ count > streak)
          {
              return WIN;
          }

          count = 0,ncount = 0, xcount =0;

          //Check Diagonal "/"
          for (int i = 0; i <= streak; i++)
          {
              if(row - 1 - i >= 0 && size > (column - 1 + i)){
                  if (board[row-1 - i][column-1 + i] == symbol && ncount == 0) {
                      count++;
                  } else {
                      ncount++;
                  }
              }
              if(size > row - 1 + i && (column - 1 - i) >= 0) {
                  if (board[row-1 + i][column-1 - i] == symbol && xcount == 0) {
                      count++;
                  } else {
                      xcount++;
                  }
              }
          }
          if(check+count > streak)
          {
              return WIN;
          }



          return CONTINUE;
}


//////////////////////////////////////////////////////////
////////////// CHECK IF GOING TO WIN//////////////////////
/////////////////////////////////////////////////////////

bool Board::gstatus(int row, int column, char symbol, int check){
    int count = 0, ncount = 0, xcount = 0;


    //Check Horizontal
    for (int i = 0; i <= streak; i++) {

        if(size -1 >= (column - 1 + i)) {
            if (board[row - 1][column - 1 + i] == symbol && ncount == 0 || i ==0) {
                count++;
            } else {
                ncount++;
            }
        }

        if (column - 1 - i >= 1) {
            if (board[row - 1][column - 1 - i] == symbol && xcount == 0|| i ==0) {
                count++;
            } else {
                xcount++;
            }
        }

    }
    if (count+check > streak) {
        return true;
    }

    count = 0,ncount = 0, xcount =0;


    // Check Vertical
    for (int i = 0; i < streak; i++) {
        if(size -1> (row - 1 + i)) {
            if (board[row - 1 + i][column - 1] == symbol && ncount == 0 || i ==0) {
                count++;
            } else {
                ncount++;
            }
        }
        if (row - 1 - i >= 1) {
            if (board[row - 1 - i][column - 1] == symbol && xcount == 0 || i ==0) {
                count++;
            } else {
                xcount++;
            }
        }
        if (count+ check > streak) {
            return true;
        }
    }

    count = 0,ncount = 0, xcount =0;

    //Check Diagonal "\"
    for (int i = 0; i <= streak; i++)
    {
        if(size - 1> (row - 1 + i) && size - 1> (column - 1 + i)) {
            if (board[row-1 + i][column-1 + i] == symbol && ncount == 0 || i ==0) {
                count++;
            } else {
                ncount++;
            }
        }

        if(row - 1 - i >= 1 && column - 1 - i >= 1){
            if (board[row-1 - i][column-1 - i] == symbol  && xcount == 0 || i ==0) {
                count++;
            } else {
                xcount++;
            }
        }

    }
    if(check+ count > streak)
    {
        return true;
    }

    count = 0,ncount = 0, xcount =0;

    //Check Diagonal "/"
    for (int i = 0; i <= streak; i++)
    {
        if(row - 1 - i >= 1 && size - 1> (column - 1 + i)){
            if (board[row-1 - i][column-1 + i] == symbol && ncount == 0 || i ==0) {
                count++;
            } else {
                ncount++;
            }
        }
        if(size - 1> row - 1 + i && (column - 1 - i) >= 0) {
            if (board[row-1 + i][column-1 - i] == symbol && xcount == 0 || i ==0) {
                count++;
            } else {
                xcount++;
            }
        }
    }
    if(check+count > streak)
    {
        return true;
    }



    return false;
}



    Board::~Board()
{
    for(int i = 0; i < size; ++i) {
        delete [] board[i];
    }
    delete [] board;

}
