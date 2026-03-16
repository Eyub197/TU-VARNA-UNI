// int A[20][20], B[20][20]

// 3 < n <= 20

// | 1  2  3  4  5
// | 16 17 18 19 6
// | 15 24 25 20 7
// | 14 23 22 21 8
// | 13 12 11 10 9

// | 1 16 15 14 13
// | 2 17 24 23 12
// | 3 18 25 22 11
// | 4 19 20 21 10
// | 5  6  7  8  9

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

void processMatrix(int a[20][20], int n) {
  cout << "\nMatrix:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(4) << a[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  int n = getN();
  int matrixOne[20][20];
  int matrixTwo[n][n];

  int matrixOneCount = 1;
  int matrixOneCountHelper = 13;
  int matriOneSecondHelper = 16;
  int matrixOneFourthHelper = 17;

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (row == 0) {
        matrixOne[row][col] = matrixOneCount;
        matrixOneCount++;
      }

      if (row > 0 && col == n - 1) {
        matrixOne[row][col] = matrixOneCount;
        matrixOneCount++;
      }

      if (row == n - 1 && col <= n - 1) {
        matrixOne[row][col] = matrixOneCountHelper;
        matrixOneCountHelper--;
        matrixOneCount++;
      }

      if (row > 0 && row < n - 1 && col == 0) {
        matrixOne[row][col] = matriOneSecondHelper--;
      }

      if (row == 1 && col > 0 && col < n - 1) {
        matrixOne[row][col] = matrixOneFourthHelper++;
      }

      if (row > 1 && row < n - 1 && col > 2 && col < n - 1) {
        matrixOne[row][col] = matrixOneFourthHelper++;
      }

      if (row == n - 2 && col > 0 && col < n - 2) {
        matrixOne[row][col] = matrixOneFourthHelper--;
      }

      // you may change the conditional
    }
  }

  processMatrix(matrixOne, n);
}
