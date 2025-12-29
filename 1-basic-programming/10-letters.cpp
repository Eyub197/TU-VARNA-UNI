#include <iostream>

using namespace std;

int main() {
  char letter;

  cout << "Enter letter : " << endl;
  cin >> letter;

  switch (letter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        cout << "Vowel";
        break;
    default:
        cout << "Consonant" ;
   }
}
