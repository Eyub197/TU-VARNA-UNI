void switchValues(int * firstNumber, int * secondNumber) {
    int holder = * firstNumber;
    * firstNumber = * secondNumber;
    * secondNumber = holder;
}

int main() {
    int firstNumber = 10;
    int secondNumber = 20;
    switchValues(&firstNumber, &secondNumber);
    return 0;
}
