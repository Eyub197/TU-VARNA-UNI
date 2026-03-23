#include <iostream>

using namespace std;

int calculate(int, int);

int main() {
  int base, power, result;
  cout << "Enter base number: ";
  cin >> base;
  cout << "Enter power number(positive integer): ";
  cin >> power;
  result = calculate(base, power);
  cout << base << "^" << power << " = " << result;
  return 0;
}

int calculate(int base, int power) {
  cout << "-> Entering calculate(base: " << base << ", power: " << power
       << ")\n";
  if (power != 0) {
    int res = base * calculate(base, power - 1);
    cout << "<- Returning " << res << " from calculate(base: " << base
         << ", power: " << power << ")\n";
    return res;
  } else {
    cout << "<- Returning 1 from calculate(base: " << base
         << ", power: 0) [Base Case]\n";
    return 1;
  }
}
