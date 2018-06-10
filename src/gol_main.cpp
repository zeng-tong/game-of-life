#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <signal.h>
#include <unistd.h>

#include "GameOfLife.hpp"
#include "DataTransfer.hpp"

using namespace std;

static unsigned long speed = 1000000; // sleep 1000000 microsecond
bool shouldPause = false;

void speedUp(int sig) {// 控制速度， 捕获信号，读取文件
    speed += 30000; // 30 ms
}

void speedDown(int sig) {
    speed -= 30000; // 30ms
}

void Pause(int sig) {
    shouldPause = !shouldPause;
}

void errorInput(const char *applicationName) {
    printf("usage: %s -r\n", applicationName);
    printf("usage: %s -f filepath\n", applicationName);
    printf("usage: %s -h\n", applicationName);
    exit(1);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, speedUp);
    signal(SIGQUIT, speedDown);
    signal(SIGTSTP, Pause);
    DataTransfer dataTransfer;
    std::vector<std::vector<int>> input;

    int opt;
    if ((opt = getopt(argc, argv, "rhf:")) != -1) {
        switch (opt) {
            case 'r' :
                input = dataTransfer.fromRandom();
                break;
            case 'f':
                input = dataTransfer.fromFile(optarg);
                break;
            case 'h':
                printf("To start by two ways.Load the initialized statu by random or from text.\n");
                printf("usage: %s -r  #from random\n", argv[0]);
                printf("usage: %s -f filepath #from text\n", argv[0]);
                printf("Speed-Up -> Ctrl(control) + \\\n");
                printf("Speed-Down -> Ctrl(control) + C\n");
                printf("Pause and look -> Ctrl(control) + Z\n");
                printf("Quit -> Just click the Close Button :)\n");
                exit(0);
            default:
                errorInput(argv[0]);
        }
    } else {
        errorInput(argv[0]);
    }

    GameOfLife gameOfLife(input);
    for (;;) {
        if (shouldPause) {
            std::cout << "Has evolved to the " << gameOfLife.getGeneration() << " generation. The speed is " << (double)1.0 / (speed / 1000000.0)
                      << std::endl;
            pause();
        }
        system("printf \"\\033c\""); // 命令行运行可清屏
        gameOfLife.showTheWorld();
        gameOfLife.nextGeneration();
        usleep(speed);
    }
    return 0;
}