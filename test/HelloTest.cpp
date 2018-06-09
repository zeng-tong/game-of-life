
#include <catch.hpp>

#include "hello.hpp"
#include <vector>
#include "solution.hpp"
// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

TEST_CASE("should return 'hello world' when call method hello()", "[hello_test]") {

    auto message = hello();

    REQUIRE(message == "hello world");

}

TEST_CASE("test") {
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));

    auto result = game_of_life(matrix);
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            REQUIRE(result[i][j] == 0);
        }
    }
}
