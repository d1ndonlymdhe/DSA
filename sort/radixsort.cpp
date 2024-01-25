#include <math.h>

#include <iostream>
using namespace std;
void innerSort(int arr[], int size, int n) {
  if (size < 1) {
    return;
  }
  int output[size];
  int count[10] = {0};
  int exp = pow(10, n);

  for (int i = 0; i < size; i++) {
    int scannedDigit = (arr[i] / exp) % 10;
    count[scannedDigit]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] = count[i - 1] + count[i];
  }
  for (int i = size - 1; i >= 0; i--) {
    int scannedDigit = (arr[i] / exp) % 10;
    output[count[scannedDigit] - 1] = arr[i];
    count[scannedDigit]--;
  }
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}

void radixSort(int arr[], int size) {
  if (size > 0) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    // count digits
    int maxDigits = 0;
    while (max != 0) {
      max = max / 10;
      maxDigits++;
    }
    for (int i = 0; i < maxDigits; i++) {
      innerSort(arr, size, i);
    }
  }
}

int main() {
  int list[] = {70, 80, 30, 10, 20, 5, 3, 100, 99, 50};
  int arrSize = (sizeof list) / (sizeof(int));
  radixSort(list, arrSize);
  for (int i = 0; i < arrSize; i++) {
    cout << list[i] << endl;
  }
}