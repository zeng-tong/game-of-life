//
// Created by tong zeng on 2018/6/9.
//
#include <fstream>
#include <sstream>
#include <iostream>
#include "DataTransfer.hpp"

std::vector<std::vector<int>> DataTransfer::fromFile(const char *filepath) {
    std::vector<std::vector<int>> result;

    std::ifstream file(filepath);
    std::string line;
    while (getline(file, line)) {
        std::istringstream is(line);

        std::istream_iterator<int> int_begin(is), eof;
        std::vector<int> row(int_begin, eof);
        result.push_back(row);
    }
    return result;
}

std::vector<std::vector<int>> DataTransfer::fromRandom() {
    int colmns = random() % MAX_COLS + 1; // avoid zero
    int rows = random() % MAX_ROWS + 1;
    std::vector<std::vector<int>> result;

    for (int row = 0; row < rows; ++row) {
        std::vector<int> line;
        for (int col = 0; col < colmns; ++col) {
            line.push_back(random() % 2 ? 1 : 0);
        }
        result.push_back(line);
    }
    return result;
}

DataTransfer::DataTransfer() {
    srand(time(NULL));
}

