#include <iostream>

int main() {
    int numbers[20];

    for (int i = 0; i < 20; i++) {
        numbers[i] = i;
    }

    std::cout << numbers;
}
