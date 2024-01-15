#include <iostream>

int main() {
    try {

    } catch(std::exception &e) {
        std::cout << e.what() << '\n';
        return 1;
    }

    return 0;
}
