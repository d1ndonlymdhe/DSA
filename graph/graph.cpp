#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define INFINITY -1

using namespace std;

template <class T>
bool vectorHas(vector<T> vec, T val) {
  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] == val) {
      return true;
    }
  }
  return false;
}

class Graph {
 public:
  vector<vector<int>> matrix;
  vector<string> names;

  int degree;
  Graph(int degree, vector<string> names) {
    this->degree = degree;
    this->names = names;
    matrix = vector<vector<int>>(degree, vector<int>(degree, 0));
  }
  void disp() {
    cout << endl;

    for (int i = 0; i < degree; i++) {
      // cout << names[i] << " ";
      for (int j = 0; j < degree; j++) {
        cout << matrix[i][j] << "  ";
      }
      cout << endl;
    }
  }
  void init() {
    for (int i = 0; i < degree; i++) {
      for (int j = 0; j < degree; j++) {
        if (i != j) {
          cout << "Enter weight for " << names[i] << " to " << names[j] << ": ";
          cin >> matrix[i][j];
        }
      }
    }
  }

  void djikstra(int idx) {
    vector<int> dist(degree, INFINITY);
    queue<int> q;
    q.push(idx);
    dist[idx] = 0;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      for (int j : getAdjacent(i)) {
        if (dist[j] == INFINITY) {
          q.push(j);
        }
        int s = dist[i] + matrix[i][j];
        dist[j] = dist[j] == INFINITY ? s : s < dist[j] ? s : dist[j];
      }
    }
    for (int i = 0; i < degree; i++) {
      cout << names[i] << " = " << dist[i] << endl;
    }
  }

  vector<vector<int>> warshall() {
    vector<vector<int>> dist(degree, vector<int>(degree, INFINITY));
    for (int i = 0; i < degree; i++) {
      for (int j = 0; j < degree; j++) {
        dist[i][j] = i == j ? 0 : matrix[i][j] != 0 ? matrix[i][j] : INFINITY;
      }
    }
    for (int k = 0; k < degree; k++) {
      for (int i = 0; i < degree; i++) {
        for (int j = 0; j < degree; j++) {
          if (dist[i][k] != INFINITY && dist[k][j] != INFINITY && i != j &&
              (i != k || j != k)) {
            int s = dist[i][k] + dist[k][j];
            if (dist[i][j] == INFINITY || dist[i][j] > s) {
              dist[i][j] = s;
            }
          }
        }
      }
    }
    return dist;
  }

  vector<int> getAdjacent(int idx) {
    vector<int> arr;
    for (int i = 0; i < degree; i++) {
      if (matrix[idx][i] > 0) {
        arr.push_back(i);
      }
    }
    return arr;
  }

  void bfs() {
    queue<int> q;
    vector<int> visited;
    q.push(0);
    visited.push_back(0);
    do {
      int v = q.front();
      q.pop();
      cout << names[v] << " " << endl;
      for (int i : getAdjacent(v)) {
        if (!vectorHas(visited, i)) {
          q.push(i);
          visited.push_back(i);
        }
      }
    } while (!q.empty());
  }

  void dfs() {
    stack<int> nodes;
    vector<int> visited;
    nodes.push(0);
    if (degree > 0) {
      while (visited.size() != degree) {
        int top = nodes.top();
        nodes.pop();
        if (!vectorHas(visited, top)) {
          cout << names[top] << endl;
          visited.push_back(top);
        }

        for (int j : getAdjacent(top)) {
          if (!vectorHas(visited, j)) {
            nodes.push(j);
          }
        }
      }
    }
  }
};

int main() {
  Graph g(6, {"A", "B", "C", "D", "E", "F"});
  g.matrix = {{0, 4, 5, 0, 0, 0},  {4, 0, 11, 9, 7, 0}, {5, 11, 0, 0, 3, 0},
              {0, 9, 0, 0, 13, 2}, {0, 7, 3, 13, 0, 6}, {0, 0, 0, 2, 6, 0}};
  g.djikstra(0);
  // g.bfs();
  g.dfs();
  // Graph f(6, {"A", "B", "C", "D", "E", "F"});
  // f.matrix = g.warshall();
  // f.disp();
}