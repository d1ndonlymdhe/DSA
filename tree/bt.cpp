#include<iostream>
using namespace std;

template <class T>
class Node{
public:
    value T;
    Node<T>* left=NULL;
    Node<T> *right=NULL;
    Node(T value,Node<T>* left,Node<T>*right){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};




int main(){
    Node<int> head(1,NULL,NULL);
}