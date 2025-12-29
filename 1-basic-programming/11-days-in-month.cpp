#include <iostream>

using namespace std;

int main() {
  int month;
  int year;

  cout << "Enter month : " << endl;
  cin >> month;

  cout << "Enter year : " << endl;
  cin >> year;

  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "The month has 31 days";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "The month has 30 days";
        break;
    case 2:
        if(year % 4 == 0) cout << "The month has 29 days";
        else cout << "The month has 28 days";
        break;
    default:
        cout << "there is no month with this number" ;
   }
}
