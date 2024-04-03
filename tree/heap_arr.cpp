#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Heap {
 public:
  vector<int> arr;
  void push(int a) {
    arr.push_back(a);
    heapify(a, arr.size() - 1);
  }
  int getParentIdx(int idx) {
    if (idx % 2 == 0) return idx / 2 - 1;
    return idx / 2;
  }

  void heapify(int a, int idx) {
    int parentIdx = getParentIdx(idx);
    if (parentIdx >= 0) {
      int parent = arr[parentIdx];
      if (parent < a) {
        arr[idx] = parent;
        arr[parentIdx] = a;
        heapify(a, parentIdx);
      }
    }
  }

  void disp() {
    int a = 0;
    int n = pow(2, a);
    for (int i = 0; i < arr.size(); i++) {
      if (i == n) {
        cout << endl;
        a++;
        n = n + pow(2, a);
      }
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  vector<int> list = {70, 80, 30, 10, 20, 5, 3, 100, 99, 50, -50,53,178};
  Heap h;
  for (int i = 0; i < list.size(); i++) {
    h.push(list[i]);
  }
  h.disp();
}
