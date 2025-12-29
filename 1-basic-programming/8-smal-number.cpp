#include <iostream>

using namespace std;

int main() {
  int firstNumber;
  int secondNuber;
  int thirdNumber;

  cout << "Enter first number: " << endl;
  cin >> firstNumber;

  cout << "Enter second number:" << endl;
  cin >> secondNuber;

  cout << "Enter third number:" << endl;
  cin >> thirdNumber;

  if((firstNumber < secondNuber) && (firstNumber << thirdNumber)) {
      cout << "The smallest number is" << firstNumber;
  } else if (secondNuber < thirdNumber) {
      cout << "The smallest number is" << secondNuber;
  } else {
      cout << "The smallest number is" << thirdNumber;
  }

}
