#include <iostream>

int main() {
    int numbers[20];
    int countOfPostiveNumbers = 0;

    for (int i = 0; i < 20; i++) {
       std::cin >> numbers[i];
    }

    for (int i = 0; i < 20; i++) {
        if (numbers[i] > 0) countOfPostiveNumbers++;
    }
}
