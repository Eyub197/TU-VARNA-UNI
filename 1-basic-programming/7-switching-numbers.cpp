#include <iostream>

using namespace std;

int main() {
  int firstNumber;
  int secondNuber;
  int holder;

  cout << "Enter first number: " << endl;
  cin >> firstNumber;

  cout << "Enter second number:" << endl;
  cin >> secondNuber;

  if(firstNumber > secondNuber) {
      holder = firstNumber;
      firstNumber = secondNuber;
      secondNuber = holder;
  }

  cout << "Biggest num is: " << secondNuber << endl;

}
