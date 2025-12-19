#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> cell;
typedef vector<vector<char>> board;

vector<vector<char>> BOARD = { { 'A', 'B', 'C', 'E' },
    { 'S', 'F', 'C', 'S' },
    { 'A', 'D', 'E', 'E' } };

bool searchChar(board& board, int height, int width, const string& word,
    unsigned index, const cell& start)
{
    // Stop condition for recursion
    if (index == word.size()) {
        return true;
    }
    // In case some idiot passes an empty board
    if (height == 0) {
        return false;
    }
    // Standard bound checking
    if (start.first < 0 || start.first >= height) {
        return false;
    }
    if (start.second < 0 || start.second >= width) {
        return false;
    }
    // Return if current character is not correct
    if (board[start.first][start.second] != word[index]) {
        return false;
    }
    // Leave breadcrumps
    char temp = board[start.first][start.second];
    board[start.first][start.second] = '@';
    // Recursive calls
    bool cell_1 = searchChar(board, height, width, word,
        index + 1, { start.first - 1, start.second });
    bool cell_2 = searchChar(board, height, width, word,
        index + 1, { start.first + 1, start.second });
    bool cell_3 = searchChar(board, height, width,
        word, index + 1, { start.first, start.second - 1 });
    bool cell_4 = searchChar(board, height, width,
        word, index + 1, { start.first, start.second + 1 });
    // Restore the board and return
    board[start.first][start.second] = temp;
    return cell_1 || cell_2 || cell_3 || cell_4;
}

bool wordExist(board board, const string& word)
{
    if (word == "") {
        return true;
    }
    int height = board.size();
    // In case some idiot passes an empty board
    if (height == 0) {
        return false;
    }
    int width = board[0].size();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (searchChar(board, height, width, word, 0, { i, j })) {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    cout << "The string \"ABCCED\" "
         << (wordExist(BOARD, "ABCCED") ? "exists " : "does not exist ")
         << "in the board." << endl;
    cout << "The string \"AMA\" "
         << (wordExist(BOARD, "AMA") ? "exists " : "does not exist ")
         << "in the board." << endl;
}
