#include "hello.hpp"
#include "GameOfLife.hpp"
#include "DataTransfer.hpp"
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <fstream>
#include <sstream>

using namespace std;

static unsigned long speed = 3000000.0;


void sigint_handler(int sig) {// 控制速度， 捕获信号，读取文件
    ifstream s("speed");
    string line;
    getline(s, line);

    istringstream is(line);
    is >> speed;
}

int main() {
    signal(SIGINT, sigint_handler);

    DataTransfer dataTransfer;
    auto input = dataTransfer.file("test/trace05.txt");
    GameOfLife gameOfLife(input);
    for(;;) {
        gameOfLife.showTheWorld();
        gameOfLife.nextGeneration();
        usleep(speed);
        system("printf \"\\033c\""); // 命令行运行可清屏
        std::cout << std::endl;
    }
    return 0;
}