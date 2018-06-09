#include "hello.hpp"
#include "solution.hpp"

#include <iostream>

using namespace std;

int main() {
    cout << hello() << endl;
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5, 0));

    for(;;) {
        matrix = game_of_life(matrix);
    }
    return 0;
}