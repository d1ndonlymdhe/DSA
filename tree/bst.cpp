#include <iostream>
using namespace std;

class BSTnode {
 public:
  int value;
  BSTnode *left = NULL;
  BSTnode *right = NULL;

  BSTnode(int value) { this->value = value; }

  void addChildren(int children[], int children_size) {
    for (int i = 0; i < children_size; i++) {
      this->addChild(new BSTnode(children[i]));
    }
  }
  void addChildren(BSTnode children[], int children_size) {
    for (int i = 0; i < children_size; i++) {
      this->addChild(children + i);
    }
  }
  void addChild(int v) {
    BSTnode *child = new BSTnode(v);
    addChild(child);
  }
  void addChild(BSTnode *child) {
    if (child) {
      if (child->value <= this->value) {
        if (this->left) {
          this->left->addChild(child);
        } else {
          this->left = child;
        }
      } else {
        if (this->right) {
          this->right->addChild(child);
        } else {
          this->right = child;
        }
      }
    }
  }
  void deleteChild(int v) {
    BSTnode *node = search(v);
    BSTnode *parent = getParent(node);
    if (node && parent) {
      //node is leaf
      if (node->left == NULL && node->right == NULL) {
        if (parent->right == node) {
          parent->right = NULL;
        } else {
          parent->left = NULL;
        }
        free(node);
      }
      //node has only one child
      if(node->left==NULL || node->right==NULL){
        if(parent->right == node){
          
        }
      }
    }
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

  BSTnode *getParent(BSTnode *n) {
    if (n) {
      if (n == this) {
        return NULL;
      }
      if (this->left == n || this->right == n) {
        return this;
      }
      if (this->left) {
        BSTnode *checkLeft = this->left->getParent(n);
        if (checkLeft) {
          return checkLeft;
        }
      }
      if (this->right) {
        BSTnode *checkRight = this->right->getParent(n);
        if (checkRight) {
          return checkRight;
        }
      }
    }
    return NULL;
  }
  BSTnode *getSibling(BSTnode *n) {
    if (n) {
      if (n == this) {
        return NULL;
      }
      BSTnode *parent = this->getParent(n);
      if (parent) {
        if (parent->left == n) {
          return parent->right;
        }
        return parent->left;
      }
    }
    return NULL;
  }
  BSTnode *search(int v) {
    if (this->value == v) {
      return this;
    }
    if (v <= this->value) {
      if (this->right) {
        return this->right->search(v);
      }
      return NULL;
    }
    if (this->left) {
      return this->left->search(v);
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
