//
// Created by tong zeng on 2018/6/9.
//

#ifndef GAME_OF_LIFE_DATATRANSFER_H
#define GAME_OF_LIFE_DATATRANSFER_H

#include <vector>

class DataTransfer{
public:
    DataTransfer();
    std::vector<std::vector<int>> fromRandom();
    std::vector<std::vector<int>> fromFile(const char *filepath);

private:
    const int MAX_COLS = 100;
    const int MAX_ROWS = 50;
};
#endif //GAME_OF_LIFE_DATATRANSFER_H
