#include "../../ExpressionEvaluator.h"

#include <unistd.h>
#include <getopt.h>
#include <iostream>
#include <iomanip>
#include <cstring>

void run();

int main(int argc, char** argv) {
    if (argc == 1) {
        run();
        return 0;
    }
    else if (argc == 2) {
        ExpressionEvaluator expEv;
        double result = expEv.eval(argv[1]);
        if (expEv.getLastError() == EXPEV_NO_ERROR) {
            std::cout << result << std::endl;
        }
        else {
            std::cout << expEv.getErrorDesc() << std::endl;
            return 1;
        }
    }
    else {
        std::cout << "Too many parameters" << std::endl;
        return 1;
    }

    return 0;
}

void run() {
    ExpressionEvaluator expEv;
    std::cout << std::setprecision(13);
    while (1) {
        // Prompt
        std::cout << ">>> ";
        std::cout.flush();

        // Get input
        char str[512];
        std::cin.getline(str, 512);

        if (strcmp(str, "exit") == 0 || strcmp(str, "quit") == 0 ||
                strcmp(str, "q") == 0) {
            break;
        }

        // Calculate
        double result = expEv.eval(str);
        if (expEv.getLastError() == EXPEV_NO_ERROR) {
            std::cout << result << std::endl;
        }
        else {
            std::cout << expEv.getErrorDesc() << std::endl;
        }
    }
}
