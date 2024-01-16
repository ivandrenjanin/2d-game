#include <iostream>
#include "core/app.hpp"

int main() {
    try {
        App app;
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
        return 1;
    }
    return 0;
}