#include <iostream>

int main() {
    int numbers[20];
    double avarage;
    double arraySum;

    for (int i = 0; i < 20; i++) {
       std::cin >> numbers[i];
    }

    for (int i = 0; i < 20; i++) {
        arraySum += numbers[i];
    }

    int length = sizeof(numbers) / sizeof(int);

    avarage = arraySum / length;
}
