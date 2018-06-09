//
// Created by tong zeng on 2018/6/9.
//

#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

class GameOfLife {
public:
    GameOfLife(std::vector<std::vector<int>> &);

    void showTheWorld();

    std::vector<std::vector<int>> nextGeneration();

private:
    std::vector<std::vector<int>> lifeOcean;
    const int DEAD = 0;
};

#endif
