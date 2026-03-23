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

void fillMatrix(int a[20][20], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }

  int r = 0, c = 0, dir = 0;
  int dr[] = {0, 1, 0, -1};
  int dc[] = {1, 0, -1, 0};

  for (int num = 1; num <= n * n; num++) {
    a[r][c] = num;
    int nextR = r + dr[dir];
    int nextC = c + dc[dir];

    if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n ||
        a[nextR][nextC] != 0) {
      dir = (dir + 1) % 4;
      nextR = r + dr[dir];
      nextC = c + dc[dir];
    }

    r = nextR;
    c = nextC;
  }
}

void fillMatrixB(int a[20][20], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }

  int r = 0, c = 0, dir = 0;
  int dr[] = {1, 0, -1, 0};
  int dc[] = {0, 1, 0, -1};

  for (int num = 1; num <= n * n; num++) {
    a[r][c] = num;
    int nextR = r + dr[dir];
    int nextC = c + dc[dir];

    if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n ||
        a[nextR][nextC] != 0) {
      dir = (dir + 1) % 4;
      nextR = r + dr[dir];
      nextC = c + dc[dir];
    }

    r = nextR;
    c = nextC;
  }
}

int main() {
  int n = getN();
  int matrixOne[20][20];
  int matrixTwo[20][20];

  fillMatrix(matrixOne, n);
  fillMatrixB(matrixTwo, n);
  processMatrix(matrixOne, n);
  processMatrix(matrixTwo, n);
}
