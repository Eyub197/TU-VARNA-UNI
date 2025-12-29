
#include <iostream>

using namespace std;

int main() {
  int monthNumber;

  cout << "Enter month number: " << endl;
  cin >> monthNumber;


switch (monthNumber) {
    case 1:
    case 2:
    case 12:
        cout << "winter";
        break;
    case 3:
    case 4:
    case 5:
        cout << "spring";
        break;
    case 6:
    case 7:
    case 8:
        cout << "summer";
        break;
    case 9:
    case 10:
    case 11:
        cout << "autumn";
        break;
    }
}
