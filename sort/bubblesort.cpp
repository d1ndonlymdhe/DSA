#include <iostream>
using namespace std;

void sort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int t = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = t;
      }
    }
  }
}

int main() {
  int list[] = {80, 30, 10, 20, 5, 3, 2, 1000, 100, 99, 90, -50};
  int arrSize = (sizeof list) / (sizeof(int));
  sort(list, arrSize);
  for (int i = 0; i < arrSize; i++) {
    cout << list[i] << endl;
  }
}