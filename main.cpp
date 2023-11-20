//
// Created by Peter May on 2023-11-19.
//

#include <iostream>

int main(int argc, char* argv[]) {
    std::string test = argv[1];
    if (argc == 2) {
        if ("test" == test) {
            std::cout << "it worked" << std::endl;
            return 0;
        }
    }
}
