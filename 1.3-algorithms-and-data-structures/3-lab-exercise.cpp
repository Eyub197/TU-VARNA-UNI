
// matrix int a[20][20]
// 3 < n <= 20
// n = 5
// | 0 20 19 17 14
// | 1 0 18 16 13
// | 2 5 0 15 12
// | 3 6 8 0 11
// | 4 7 9 10 0
//

// matrix population

#include <iomanip>
#include <iostream>

using namespace std;

int getN() {
  int userInput;
  do {
    cout << "Enter a number n between 3 and 20: ";
    cin >> userInput;
  } while (userInput <= 3 || userInput > 20);
  return userInput;
}

void populateMatrix(int a[20][20], int n) {
  int currentVal = 1;

  for (int i = 0; i < n; i++) {
    a[i][i] = 0;
  }

  for (int j = 0; j < n; j++) {
    for (int i = j + 1; i < n; i++) {
      a[i][j] = currentVal++;
    }
  }

  for (int j = n - 1; j > 0; j--) {
    for (int i = j - 1; i >= 0; i--) {
      a[i][j] = currentVal++;
    }
  }

  // Print the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(4) << a[i][j];
    }
    cout << endl;
  }
}

int main() {
  int a[20][20];
  int n = getN();
  populateMatrix(a, n);
  return 0;
}
