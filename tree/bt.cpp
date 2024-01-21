#include <iostream>
using namespace std;
class Bnode {
 public:
  int value;
  Bnode *left = NULL;
  Bnode *right = NULL;
  Bnode(int value, Bnode *left, Bnode *right) {
    this->value = value;
    this->left = left;
    this->right = right;
  }
  void setLeft(Bnode *node) {
    Bnode *n = this;
    while (n->left != NULL) {
      n = n->left;
    }
    n->left = node;
  }
  void setLeft(int value) {
    Bnode *n = new Bnode(value, NULL, NULL);
    setLeft(n);
  }
  void setRight(Bnode *node) {
    Bnode *n = this;
    while (n->right != NULL) {
      n = n->right;
    }
    n->right = node;
  }
  void setRight(int value) {
    Bnode *n = new Bnode(value, NULL, NULL);
    setRight(n);
  }
  void preorder() {
    cout << this->value << endl;
    if (this->left) {
      this->left->preorder();
    }
    if (this->right) {
      this->right->preorder();
    }
  }
  void inorder() {
    if (this->left) {
      this->left->inorder();
    }
    cout << this->value << endl;
    if (this->right) {
      this->right->inorder();
    }
  }
  void postorder() {
    if (this->left) {
      this->left->postorder();
    }
    if (this->right) {
      this->right->postorder();
    }
    cout << this->value << endl;
  }
  Bnode *getParent(Bnode *n) {
    if (n) {
      if (n == this) {
        return NULL;
      }
      if (this->left == n || this->right == n) {
        return this;
      }
      if (this->left) {
        Bnode *checkLeft = this->left->getParent(n);
        if (checkLeft) {
          return checkLeft;
        }
      }
      if (this->right) {
        Bnode *checkRight = this->right->getParent(n);
        if (checkRight) {
          return checkRight;
        }
      }
    }
    return NULL;
  }
  Bnode *getSibling(Bnode *n) {
    if (n) {
      if (n == this) {
        return NULL;
      }
      Bnode *parent = this->getParent(n);
      if (parent) {
        if (parent->left == n) {
          return parent->right;
        }
        return parent->left;
      }
    }
    return NULL;
  }
  int size(int initSize = 0) {
    int s = initSize + 1;
    if (this->left) {
      s = this->left->size(s);
    }
    if (this->right) {
      s = this->right->size(s);
    }
    return s;
  }
};


int main()
{
    Bnode E(5, NULL, NULL);
    Bnode D(4, NULL, NULL);
    Bnode C(3, &D, &E);
    Bnode B(2, &C, NULL);
    Bnode A(1, NULL, NULL);
    Bnode head(10, NULL, NULL);
    head.setLeft(&B);
    head.setRight(&A);
    cout << "preorder" << endl;
    head.preorder();
    cout << "postorder" << endl;
    head.postorder();
    cout << "inorder" << endl;
    head.inorder();

    cout << "size = " << head.size() << endl;
    return 0;
}