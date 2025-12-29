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
    const int ARRAY_LENGTH = 12;
    int numbers[ARRAY_LENGTH] = { 1, 2, 3, 3, 4, 5, 5, 5, 5, 6, 7, 7 };
    int lineCount;

    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        if(numbers[i] == numbers[i + 1]) {
            lineCount = lineCount + 1;
        }

    }
    std::cout << lineCount;
}
