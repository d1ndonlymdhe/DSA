#include <iostream>
using namespace std;

class AVLnode {
 public:
  int value;
  int balanceFactor = 0;
  AVLnode *left = NULL;
  AVLnode *right = NULL;
  AVLnode(int value) { this->value = value; }
  AVLnode(int children[], int children_size) {
    if (children_size > 0) {
      value = children[0];
      for (int i = 1; i < children_size; i++) {
        this->addChild(children[i]);
      }
    }
  }
  void addChildren(int children[], int children_size) {
    for (int i = 0; i < children_size; i++) {
      this->addChild(new AVLnode(children[i]));
    }
  }
  void addChildren(AVLnode children[], int children_size) {
    for (int i = 0; i < children_size; i++) {
      this->addChild(children + i);
    }
  }
  void addChild(int v) {
    AVLnode *child = new AVLnode(v);
    addChild(child);
  }
  void addChild(AVLnode *child) {
    if (child) {
      if (child->value == this->value) {
        return;
      }
      if (child->value < this->value) {
        if (this->left) {
          this->left->addChild(child);
          balanceFactor += this->left->balanceFactor -
                          (this->right ? this->right->balanceFactor : 0);
        } else {
          balanceFactor++;
          this->left = child;
        }
      } else {
        if (this->right) {
          this->right->addChild(child);
          //   balanceFactor++;
          balanceFactor += this->left ? this->left->balanceFactor
                                     : 0 + this->right->balanceFactor;
        } else {
          balanceFactor--;
          this->right = child;
        }
      }
    }
  }
  AVLnode *getMin() {
    if (this->left) {
      return this->left->getMin();
    } else {
      return this;
    }
  }
  AVLnode *getMax() {
    if (this->right) {
      return this->right->getMax();
    } else {
      return this;
    }
  }
  void deleteChild(int v) {
    AVLnode *node = search(v);
    AVLnode *parent = getParent(node);
    if (node && parent) {
      // node is leaf
      if (node->left == NULL && node->right == NULL) {
        if (parent->right == node) {
          parent->right = NULL;
        } else {
          parent->left = NULL;
        }
        free(node);
      }
      // node has both left and right
      if (node->left != NULL && node->right != NULL) {
        AVLnode *minNode = node->right->getMin();
        AVLnode *minParent = this->getParent(minNode);
        if (minParent->left == minNode) {
          minParent->left = NULL;
        } else {
          minParent->right = NULL;
        }
        AVLnode *nodeRight = node->right == minNode ? NULL : node->right;
        AVLnode *nodeLeft = node->left == minNode ? NULL : node->left;
        if (parent->right == node) {
          parent->right = NULL;
        } else {
          parent->left = NULL;
        }
        minNode->addChild(nodeRight);
        minNode->addChild(nodeLeft);
        parent->addChild(minNode);
        free(node);
      }
      // node has only one child
      if (node->left == NULL || node->right == NULL) {
        AVLnode *nodeChild = node->left ? node->left : node->right;
        if (parent->right == node) {
          parent->right = NULL;
        } else {
          parent->left = NULL;
        }
        parent->addChild(nodeChild);
        free(node);
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
  AVLnode *getParent(AVLnode *n) {
    if (n) {
      if (n == this) {
        return NULL;
      }
      if (this->left == n || this->right == n) {
        return this;
      }
      if (this->left) {
        AVLnode *checkLeft = this->left->getParent(n);
        if (checkLeft) {
          return checkLeft;
        }
      }
      if (this->right) {
        AVLnode *checkRight = this->right->getParent(n);
        if (checkRight) {
          return checkRight;
        }
      }
    }
    return NULL;
  }
  AVLnode *getSibling(AVLnode *n) {
    if (n) {
      if (n == this) {
        return NULL;
      }
      AVLnode *parent = this->getParent(n);
      if (parent) {
        if (parent->left == n) {
          return parent->right;
        }
        return parent->left;
      }
    }
    return NULL;
  }
  AVLnode *search(int v) {
    if (this->value == v) {
      return this;
    }
    if (v > this->value) {
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
  void balance(AVLnode *node) {}
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

int main() {
  int arr[] = {5, 3, 6, 7, 1, 76, 34, 23, 71, 0, 524, 521, 523};
  AVLnode tree(arr, (sizeof arr) / (sizeof(int)));
  tree.deleteChild(6);
  tree.deleteChild(76);
  cout << "PREORDER" << endl;
  tree.preorder();
  cout << "INORDER" << endl;
  tree.inorder();
  cout << "POSTORDER" << endl;
  tree.postorder();

  AVLnode *x = tree.search(71);
  cout << "Searched value" << x->value << endl;

  AVLnode *max = tree.getMax();
  AVLnode *min = tree.getMin();
  cout << "Max = " << max->value << " Min = " << min->value << endl;
}
