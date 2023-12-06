#include <iostream>
using namespace std;
template <class T> class Node {

public:
  T value;
  Node<T> *next;
  Node(T value, Node<T> *next = NULL) {
    this->value = value;
    this->next = next;
  }
};

template <class T> class LinkedList {
  Node<T> *head;

public:
  LinkedList(T headValue) { head = new Node(headValue); }
  bool isEmpty() { return head == NULL; }
  Node<T> *getLast() {
    if (isEmpty()) {
      return NULL;
    } else {
      Node<T> *n = head;
      while (n->next != NULL) {
        n = n->next;
      }
      return n;
    }
  }
  void append(T value) {
    if (isEmpty()) {
      head = new Node(value);
    } else {
      getLast()->next = new Node(value);
    }
  }
  bool append_at_value(T search, T value) {
    if (!isEmpty()) {
      Node<T> *n = head;
      while (n->value != search) {
        if (n->next != NULL) {
          n = n->next;
        } else {
          return false;
        }
      }
      n->next = new Node(value, n->next);
      return true;
    }
    return false;
  }
  void deleteLast() {
    if (!isEmpty()) {
      if (head->next == NULL) {
        Node<T> *freeThis = head;
        head = NULL;
        free(freeThis);
      }

      Node<T> *n = head;
      while (n->next->next != NULL) {
        n = n->next;
      }
      Node<T> *freeThis = n->next;
      n->next = NULL;
      free(freeThis);
    }
  }
  bool delete_at_value(T search) {
    if (!isEmpty()) {
      Node<T> *n = head;
      while (n->next->value != search) {
        if (n->next != NULL) {
          n = n->next;
        } else {
          return false;
        }
      }
      Node<T> *freeThis = n->next;
      n->next = n->next->next;
      free(freeThis);
      return true;
    }
    return false;
  }
  Node<T> *search(T value) {
    if (!isEmpty()) {
      Node<T> *n = head;
      while (n->next != NULL) {
        if (n->value == value) {
          return n;
        }
        n = n->next;
      }
      return NULL;
    } else {
      throw range_error("List is empty");
    }
  }
  void listAll() {
    cout << "---------" << endl;
    if (!isEmpty()) {
      Node<T> *n = head;
      while (n->next != NULL) {
        cout << n->value << endl;
        n = n->next;
      }
      cout << n->value << endl;
    }
    cout << "--------" << endl;
  }
};

int main() {
  LinkedList<int> LL(0);
  LL.append(1);
  LL.append(2);
  LL.append(3);
  // 0 1 2 3
  LL.listAll();
  LL.append_at_value(2, 5);
  // 0 1 2 5 3
  LL.listAll();
  LL.append(6);
  LL.append(7);
  LL.deleteLast();
  // 0 1 2 5 3 6
  LL.delete_at_value(1);
  // 0 2 5 3 6
  LL.listAll();
  
  LL.search(5)->value =10;
  // 0 2 10 3 6
  LL.listAll();

}
