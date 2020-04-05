#include "../../ExpressionEvaluator.h"

#include <fstream>
#include <string>
#include <iostream>


int main() {
    ExpressionEvaluator expEv;

    std::ifstream ifs("expression.list");
    if (!ifs.is_open()) {
        std::cerr << "ERROR: Open file 'expressio.list' failed!";
        return 1;
    }

    std::string line;
    while (getline(ifs, line)) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "EXP: " << line << std::endl;
        double val = expEv.eval(line);
        if (expEv.getLastError() == EXPEV_NO_ERROR) {
            std::cout << "RPN: ";
            for (const std::string& token : expEv.getRPN()) {
                std::cout << token << " ";
            }
            std::cout << std::endl;
            std::cout << "ANS: " << expEv.getStdExp() << "=" << val << std::endl;
        }
        else {
            std::cout << expEv.getErrorDesc() << std::endl;
        }
    }

    ifs.close();
    return 0;
}
