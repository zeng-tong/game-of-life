//
// Created by tong zeng on 2018/6/9.
//
#include "GameOfLife.hpp"
#include <vector>
#include <iostream>

bool validPosition(int x, int y, int row, int col) {
    return x >= 0 && x <= row && y >= 0 && y <= col;
}

GameOfLife::GameOfLife(std::vector<std::vector<int>> &matrix) : lifeOcean(matrix), generation(1) {
}

void GameOfLife::showTheWorld() {
    for (auto row: lifeOcean) {
        for (auto cell: row) {
            if (cell) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> GameOfLife::nextGeneration() {
    if (lifeOcean.empty())
        return lifeOcean;

    auto res = lifeOcean;
    int row = lifeOcean.size() - 1;
    int col = lifeOcean[0].size() - 1;

    int rowOffset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i <= row; ++i) {
        for (int j = 0; j <= col; ++j) {
            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int x = i + rowOffset[k];
                int y = j + colOffset[k];
                if (validPosition(x, y, row, col) && lifeOcean[x][y] != DEAD)
                    ++count;
            }
            if (count == 3)
                res[i][j] = 1;
            else if (count < 2 || count > 3)
                res[i][j] = 0;
        }
    }
    this->lifeOcean = res;
    this->setGeneration(this->getGeneration() + 1);
    return res;
}

int GameOfLife::getGeneration() {
    return this->generation;
}

void GameOfLife::setGeneration(int generation) {
    this->generation = generation;
}