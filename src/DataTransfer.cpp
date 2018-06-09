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
        std::vector<int> row;
        for(int tmp; is >> tmp;) {
            row.push_back(tmp);
        }
        result.push_back(row);
    }
    return result;
}

