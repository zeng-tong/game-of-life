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
    speed *= 1000000;
}

void sigup_handler(int sig) {
    shouldPause = !shouldPause;
}

void errorInput(const char *applicationName) {
    printf("usage: %s -r\n", applicationName);
    printf("usage: %s -f filepath\n", applicationName);
    exit(1);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigup_handler);
    DataTransfer dataTransfer;
    std::vector<std::vector<int>> input;

    int opt;
    if ((opt = getopt(argc, argv, "rf:")) != -1) {
        switch (opt) {
            case 'r' :
                input = dataTransfer.fromRandom();
                break;
            case 'f':
                input = dataTransfer.fromFile(optarg);
                break;
            default:
                errorInput(argv[0]);
        }
    } else {
        errorInput(argv[0]);
    }

    GameOfLife gameOfLife(input);
    for (;;) {
        if (shouldPause) {
            std::cout << "Has evolved to the " << gameOfLife.getGeneration() << " generation" << std::endl;
            pause();
        }
        system("printf \"\\033c\""); // 命令行运行可清屏
        gameOfLife.showTheWorld();
        gameOfLife.nextGeneration();
        usleep(speed);
    }
    return 0;
}