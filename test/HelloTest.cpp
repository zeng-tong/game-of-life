
#include <catch.hpp>

#include "hello.hpp"
#include <vector>
#include <iostream>
#include "solution.hpp"
// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

TEST_CASE("should return 'hello world' when call method hello()", "[hello_test]") {

    auto message = hello();

    REQUIRE(message == "hello world");

}

TEST_CASE("input all dead, should return all dead when call game_of_life(). Not concern edge") {
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));

    auto result = game_of_life(matrix);
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            REQUIRE(result[i][j] == 0);
        }
    }
}

TEST_CASE("input all dead, Now concern edge cell. should return all dead when call game_of_life()") {
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));
    auto result = game_of_life(matrix);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            REQUIRE(result[i][j] == 0);
        }
    }
}

TEST_CASE("input all live") {
    std::vector<std::vector<int>> input(5, std::vector<int>(5, 1));

    std::vector<std::vector<int>> output(5, std::vector<int>(5, 0));
    output[0][0] = output[0][4] =  output[4][0] = output[4][4] = 1;


    auto result = game_of_life(input);
    printMatrix(result);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
//            std::cout << "i = " << i << ", j = " << j << " result[i][j] = "<< result[i][j] << std::endl;
            REQUIRE(result[i][j] == output[i][j]);
        }
    }
}
