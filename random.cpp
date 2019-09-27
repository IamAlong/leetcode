#include <iostream>
#include <random>
#include <functional>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99);
    auto dice = std::bind(dist, mt);

    for (int i = 0; i < 100; i++) {
        std::cout << dice() << std::endl;
    }

    return 0;
}
