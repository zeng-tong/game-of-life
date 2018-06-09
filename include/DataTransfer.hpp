//
// Created by tong zeng on 2018/6/9.
//

#ifndef GAME_OF_LIFE_DATATRANSFER_H
#define GAME_OF_LIFE_DATATRANSFER_H

#include <vector>

class DataTransfer{
public:
    std::vector<std::vector<int>> standard();
    std::vector<std::vector<int>> file(const char* filepath);
};
#endif //GAME_OF_LIFE_DATATRANSFER_H
