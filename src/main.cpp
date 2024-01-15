#include <iostream>

int main() {
    try {
        std::cout << "Hello, World!" << '\n';
    } catch(std::exception &e) {
        std::cout << e.what() << '\n';
        return 1;
    }

    return 0;
}
