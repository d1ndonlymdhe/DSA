#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class NoValueException : public exception {};

struct HashCell {
  int value;
  bool isSet;
  HashCell() {
    value = 0;
    isSet = false;
  }
  HashCell(int value) {
    this->value = value;
    this->isSet = true;
  }
};

class HashTable {
 public:
  HashCell* cells;
  size_t size;
  function<size_t(int)> hashFunc;
  HashTable(size_t size) {
    cells = new HashCell[size];
    this->size = size;
    this->hashFunc = [size](int v) { return v % size; };
  }
  HashTable(size_t size, function<size_t(int)> hashFunc) {
    cells = new HashCell[size];
    this->size = size;
    this->hashFunc = hashFunc;
  }
  void add(int v) { cells[hashFunc(v)] = HashCell(v); }
  bool contains(int v) { return cells[hashFunc(v)].isSet; }
  void remove(int v) { cells[hashFunc(v)] = HashCell(); }
  vector<int> asVector() {
    vector<int> vec;
    for (size_t i = 0; i < size; i++) {
      if (cells[i].isSet) {
        vec.push_back(cells[i].value);
      }
    }
    return vec;
  }
};

int main() {
  function<size_t(int)> endFold = [](int vv) {
    int v = vv;
    int a = v / 100000;
    v = v - a * 100000;
    int b = v / 10;
    v = v - b * 10;
    size_t k = (a + b + v) % (1000);
    cout << vv << " " << k << endl;
    return k;
  };
  HashTable table = HashTable(1000, endFold);
  table.add(4766934);
  table.add(5656975);
  table.add(4685637);
  table.add(3547807);
  table.add(7569664);
  for (int v : table.asVector()) {
    cout << v << endl;
  }
}