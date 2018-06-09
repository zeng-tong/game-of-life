//
// Created by tong zeng on 2018/6/9.
//

#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

class GameOfLife {
public:
    explicit GameOfLife(std::vector<std::vector<int>> &);

    void showTheWorld();

    std::vector<std::vector<int>> nextGeneration();
    void setGeneration(int);
    int getGeneration();
private:
    std::vector<std::vector<int>> lifeOcean;
    int generation;
    const int DEAD = 0;
};

#endif
