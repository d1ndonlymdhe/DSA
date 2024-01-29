#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left, int pivot, vector<int> right) {
  vector<int> arr;
  for (size_t i = 0; i < left.size(); i++) {
    arr.push_back(left[i]);
  }
  arr.push_back(pivot);
  for (size_t i = 0; i < right.size(); i++) {
    arr.push_back(right[i]);
  }
  return arr;
}

vector<int> sort(vector<int> arr) {
  size_t size = arr.size();
  if (size == 0) {
    return {};
  }
  if (size == 1) {
    return arr;
  }
  if (size == 2) {
    if (arr[1] < arr[0]) {
      int t = arr[0];
      arr[0] = arr[1];
      arr[1] = t;
    }
    return arr;
  }
  vector<int> left, right;
  size_t pivotIdx = size / 2;
  int smallEqCount = 0;
  int largeCount = 0;
  for (size_t i = 0; i < size; i++) {
    if (i != pivotIdx) {
      if (arr[i] <= arr[pivotIdx]) {
        smallEqCount++;
        left.push_back(arr[i]);
      } else {
        largeCount++;
        right.push_back(arr[i]);
      }
    }
  }
  vector<int> leftSort = sort(left);
  int pivot = arr[pivotIdx];
  vector<int> rightSort = sort(right);
  return merge(leftSort, pivot, rightSort);
}

int main() {
  vector<int> arr = {70, 80, 30, 10, 20, 5, 3, 100, 99, 50};
  vector<int> b = sort(arr);
  for (size_t i = 0; i < b.size(); i++) {
    cout << b[i] << endl;
  }
}