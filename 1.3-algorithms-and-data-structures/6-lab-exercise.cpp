// int a[10] b[10]
// input a from keyboard diffrent numbers
// we check every number if a number is even we do a recurstion for ^2 else ^3
// and whatever we get we input it in B
//  print B in and count of even numbers in b
// if even numbers in b are more then 5 we sort it with exchange sort
// else with odd-even sort

#include <iostream>

using namespace std;

void fillArrayA(int a[10], int n) {
  cout << "Enter 10 array numbers: ";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}

int handlePowerUp(int base, int power) {
  if (power != 0) {
    int res = base * handlePowerUp(base, power - 1);
    return res;
  } else {
    return 1;
  }
}

void fillArrayB(int arrayB[10], int n, int arrayA[10]) {
  for (int i = 0; i < n; i++) {
    if (arrayA[i] % 2 == 0) {
      arrayB[i] = handlePowerUp(arrayA[i], 2);
    } else {
      arrayB[i] = handlePowerUp(arrayA[i], 3);
    }
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
}

void exchangeSort(int arr[10], int n) {
  for (int i = 0; i < (n - 1); i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void oddEvenSort(int arr[10], int n) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;

    for (int i = 1; i < (n - 1); i = i + 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = false;
      }
    }
    sorted = true;
    for (int i = 1; i < (n - 1); i = i + 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = false;
      }
    }
  }
}

void handleSorting(int arr[10], int n) {
  int evenCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenCount++;
    }
  }

  cout << "Even cout: " << evenCount << endl;

  if (evenCount >= 5) {
    exchangeSort(arr, 10);
    cout << "Used exchange sort: ";
  } else {
    oddEvenSort(arr, 10);
    cout << "Used odd even sort: ";
  }
  printArray(arr, 10);
}

int main() {
  int arrayA[10] = {};
  int arrayB[10] = {};
  fillArrayA(arrayA, 10);
  cout << "Array A: ";
  printArray(arrayA, 10);
  fillArrayB(arrayB, 10, arrayA);
  cout << "Array B: ";
  printArray(arrayB, 10);
  handleSorting(arrayB, 10);
}
