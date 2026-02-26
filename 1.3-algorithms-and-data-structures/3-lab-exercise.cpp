#include <algorithm>
#include <iostream>

using namespace std;

/**
 * TU Varna - ASD / UP
 * Problem: array shifting
 */

// Helper function to print raw arrays
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
}

void handlePositiveKValue() {}

int main() {
  const int n = 10;
  int k = -3;
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int tempArr[k];
  int secondTempArr[n - k];

  // Start manual logic here

  if (k > 0) {
    for (int i = 0; i < k; i++) {
      tempArr[i] = arr[n - k + i];
    }

    for (int i = 0; i < n - k; i++) {
      secondTempArr[i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
      if (i < k) {
        arr[i] = tempArr[i];
      } else {
        arr[i] = secondTempArr[i - k];
      }
    }
  } else {
    k = k * -1;
    for (int i = 0; i < k; i++) {
      tempArr[i] = arr[k - i - 1];
    }

    for (int i = 0; i < n - k; i++) {
      if (i < n) {
        secondTempArr[i] = arr[i];
        cout << secondTempArr[i];
      }
    }

    for (int i = 0; i < n; i++) {
      if (i < k) {
        arr[i] = tempArr[i];
      } else {
        arr[i] = secondTempArr[i - k];
      }
    }
  }

  return 0;
}
// to finish
