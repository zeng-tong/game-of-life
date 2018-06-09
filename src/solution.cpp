//
// Created by tong zeng on 2018/6/9.
//
#include "solution.hpp"
#include <vector>

bool judge(int x, int y, int row, int col) {
    if (x >= 1 && x < row && y >= 1 && y < col)
        return true;
    return false;
}

std::vector<std::vector<int>> game_of_life(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int i, j;
    for (i = 1; i <= row - 1; ++i) { // 先绕过边界
        int count = 0;
        for (j = 1; j <= col - 1; ++j) {
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (judge(x, y, row, col) && matrix[x][y] == 1) ++count;
            }
        }
        if (count == 3)
            matrix[i][j] = 1;
        else if (count < 2 || count > 3)
            continue;
        else
            matrix[i][j] = 0;
    }
    return matrix;
}
