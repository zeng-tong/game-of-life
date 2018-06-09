#include "hello.hpp"
#include "GameOfLife.hpp"
#include "DataTransfer.hpp"
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <fstream>
#include <sstream>

using namespace std;

static unsigned long speed = 1000000; // microsecond
bool shouldPause = false;

void sigint_handler(int sig) {// 控制速度， 捕获信号，读取文件
    ifstream s("speed");
    string line;
    getline(s, line);

    istringstream is(line);
    is >> speed;
}
void sigup_handler(int sig) {
    shouldPause = !shouldPause;
}

int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigup_handler);
    DataTransfer dataTransfer;
    auto input = dataTransfer.file("test/trace05.txt");
    GameOfLife gameOfLife(input);
    for(;;) {
        gameOfLife.showTheWorld();
        gameOfLife.nextGeneration();
        if (shouldPause) {
            pause();
        }
        std::cout << "Has evolved to the " << gameOfLife.getGeneration() << " generation" << std::endl;
        usleep(speed);
        system("printf \"\\033c\""); // 命令行运行可清屏
    }
    return 0;
}