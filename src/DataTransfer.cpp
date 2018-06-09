//
// Created by tong zeng on 2018/6/9.
//
#include <fstream>
#include <sstream>
#include <iostream>
#include "DataTransfer.hpp"

std::vector<std::vector<int>> DataTransfer::file(const char *filepath) {
    std::vector<std::vector<int>> result;

    std::ifstream file(filepath);
    std::string line;
    while(getline(file, line)) {
        std::istringstream is(line);

        std::istream_iterator<int> int_begin(is), eof;
        std::vector<int> row(int_begin, eof);
        result.push_back(row);
    }
    return result;
}

