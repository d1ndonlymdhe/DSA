#include <iostream>
#include <vector>
using namespace std;
void swap(int *a, int *b) {
  int t = *b;
  *b = *a;
  *a = t;
}

int findUp(int arr[], int start, int end, int key) {
  for (int i = start; i >= end; i--) {
    if (arr[i] < key) {
      return i;
    }
  }
  return end;
}

int findDown(int arr[], int start, int end, int key) {
  for (int i = start; i < end; i++) {
    if (arr[i] > key) {
      return i;
    }
  }
  return end;
}

void sort(int arr[], int start, int end) {
  int size = end - start;
  if (size > 1) {
    int key = arr[start];
    int up = end - 1;
    int down = start;
    while (down < up) {
      if (up >= 0) {
        up = findUp(arr, up, start, key);
      }
      if (down < end) {
        down = findDown(arr, down, end, key);
      }
      if (up > down) {
        swap(&arr[up], &arr[down]);
      }
    }
    swap(&arr[start], &arr[up]);
    sort(arr, 0, up);
    sort(arr, down, end);
  }
  return;
}

int main() {
  int arr[] = {24, 2, 45, 20, -67, 56, 75, 2, 56, 99, 53, 12};
  sort(arr, 0, (sizeof arr) / (sizeof(int)));
  for (int a : arr) {
    cout << a << endl;
  }
}