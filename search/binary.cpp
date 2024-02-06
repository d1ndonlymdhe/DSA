#include <math.h>
#include <iostream>
using namespace std;
int binarySearch(int el, int arr[], int size) {
  int count = 0;
  int start = 0;
  int end = size - 1;
  int max = ceil(log2(size));
  int idx = end / 2;
  do {
    if (el == arr[idx]) {
      return idx;
    }
    if (el < arr[idx]) {
      end = idx;
      int dec = floor((float)(end - start) / 2);
      idx = idx - dec;
    }
    if (el > arr[idx]) {
      start = idx;
      int inc = ceil((float)(end - start) / 2);
      idx = idx + inc;
    }
    count++;
  } while (count < max);
  return -1;
}

void insertSort(int *list, int size) {
  if (size < 1) {
    return;
  }
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (list[j] > list[i]) {
        int small = list[i];
        for (int k = i; k > j; k--) {
          list[k] = list[k - 1];
        }
        list[j] = small;
      }
    }
  }
  return;
}

int main() {
  int list[] = {70, 80, 30, 10, 20, 5, 3, 100, 99, 50, -50};
  int arrSize = (sizeof list) / (sizeof(int));
  insertSort(list, arrSize);
  for (int i = 0; i < arrSize; i++) {
    cout << i << " " << list[i] << endl;
  }
  int x = binarySearch(20, list, arrSize);
  cout << x << endl;
}
