#include <iostream>
using namespace std;

void sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
}

int main() {
  int list[] = {70, 80, 30, 10, 20, 5, 3, 100, 99, 50};
  int arrSize = (sizeof list) / (sizeof(int));
  sort(list, arrSize);
  for (int i = 0; i < arrSize; i++) {
    cout << list[i] << endl;
  }
}