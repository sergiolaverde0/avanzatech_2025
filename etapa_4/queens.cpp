#include "queens.hpp"
#include <iostream>
#include <vector>

using namespace std;

bool validBoard(const vector<int>& board, const int& pos)
{
    bool retVal = true;
    for (int i = 0; i < pos; i++) {
        retVal = retVal && board[i] != board[pos];
        retVal = retVal && (board[i] - i) != (board[pos] - pos);
        retVal = retVal && (board[i] + i) != (board[pos] + pos);
    }
    return retVal;
}

bool placeQueen(vector<int>& board, const int& pos)
{
    for (int k = 0; k < 8; k++) {
        board[pos] = k;
        if (validBoard(board, pos)) {
            if (pos == 7) {
                return true;
            } else if (placeQueen(board, pos + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> board(8);
    placeQueen(board, 0);
    for (int pos : board) {
        cout << pos << " ";
    }
    cout << endl;
    return 0;
}
