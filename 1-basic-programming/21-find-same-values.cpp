#include <iostream>

void bubbleSort(int array[], int lengthOfArray) {
    bool ok;
    do {
        ok = 1;
        for(int i = 0; i < lengthOfArray - 1; i++) {
            if(array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                ok = 0;
            }
        }
    }while (ok == 0);
}

int main() {
    const int ARRAY_LENGTH = 5;
    int numbers[ARRAY_LENGTH] = { 10, 15, 20, 12, 20 };

    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        std::cout << numbers[i] << std::endl;
    }

    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        if(numbers[i] == numbers[i + 1]) {
            std::cout << numbers[i];
            std::cout << numbers[i + 1];
        }
    }
}
