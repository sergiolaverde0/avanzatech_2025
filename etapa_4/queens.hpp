#ifndef QUEENS_HPP
#define QUEENS_HPP

#include <vector>

bool validBoard(const std::vector<int>& board, const int& pos);

bool placeQueen(std::vector<int>& board, const int& pos);

#endif // !QUEENS_HPP
