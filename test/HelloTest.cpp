
#include <catch.hpp>

#include "hello.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include "DataTransfer.hpp"
#include "solution.hpp"
// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

void match(std::vector<std::vector<int>>& source, std::vector<std::vector<int>>& target, int i = 0, int j = 0) {
    REQUIRE(source.size() == target.size());
    for (; i < source.size(); ++i) {
        for (; j < source[i].size(); ++j) {
            REQUIRE(source[i][j] == target[i][j]);
        }
    }
}


void compareFromRead(const char* tracePath, const char* standardPath) {
    DataTransfer dataTransfer;
    auto input = dataTransfer.file(tracePath);
    auto standardOutput = dataTransfer.file(standardPath);

    GameOfLife gameOfLife(input);
    auto output = gameOfLife.nextGeneration();
    match(output, standardOutput);
}

TEST_CASE("input all dead, should return all dead when call game_of_life(). Not concern edge") {
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));
    GameOfLife gameOfLife(matrix);
    auto result = gameOfLife.nextGeneration();
    match(result, matrix, 1, 1);
}

TEST_CASE("input all dead, Now concern edge cell. should return all dead when call game_of_life()") {
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));
    GameOfLife gameOfLife(matrix);

    auto result = gameOfLife.nextGeneration();
    match(result,matrix);
}

TEST_CASE("input all live") {
    std::vector<std::vector<int>> input(5, std::vector<int>(5, 1));

    std::vector<std::vector<int>> target(5, std::vector<int>(5, 0));
    target[0][0] = target[0][4] =  target[4][0] = target[4][4] = 1;

    GameOfLife gameOfLife(input);
    auto output = gameOfLife.nextGeneration();
    match(output, target);
}

TEST_CASE("input from text01") {
    std::vector<std::vector<int>> target = { {1,1,1,1},
                                             {1,1,1,1},
                                             {1,1,1,1},
                                             {1,1,1,1},
                                             {1,1,1,1}};
    DataTransfer dataTransfer;
    auto output = dataTransfer.file("trace01.txt");
    match(output, target);
}

TEST_CASE("input from text02") {
    compareFromRead("trace02.txt", "standard02.txt");
}

TEST_CASE("input from text03") {
    compareFromRead("trace03.txt", "standard03.txt");
}
TEST_CASE("input from text04") {
    compareFromRead("trace04.txt", "standard04.txt");
}