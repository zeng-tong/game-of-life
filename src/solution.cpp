//
// Created by tong zeng on 2018/6/9.
//
#include "solution.hpp"
#include <vector>
#include <iostream>

bool judge(int x, int y, int row, int col) {
    return x >= 0 && x <= row && y >= 0 && y <= col;
}

std::vector<std::vector<int>> game_of_life(std::vector<std::vector<int>>& matrix) {
    auto res = matrix;
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i <= row; ++i) { // 先绕过边界
        for (int j = 0; j <= col; ++j) {
            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (judge(x, y, row, col) && matrix[x][y] == 1)
                    ++count;
            }
//            std::cout << "i = " << i << ", j = " << j << " result[i][j] = "<< matrix[i][j] << " count = " << count << std::endl;
            if (count == 3)
                res[i][j] = 1;
            else if (count < 2 || count > 3)
                res[i][j] = 0;
        }
    }
    return res;
}


void printMatrix(std::vector<std::vector<int>>& matrix) {
    for(auto vec: matrix) {
        for(auto n: vec) {
            if (n) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}
