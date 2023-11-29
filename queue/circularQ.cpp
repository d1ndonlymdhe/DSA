#include<iostream>
using namespace std;

template <class T>
class Q{
    T* values;
    int rear = -1;
    int front = -1;
    int size = 0;
    public:
        Q(int size){
            values = (T*)(calloc(size,sizeof(T)));
            this->size = size;
        }
        void enQueue(T v){
            if( size>0 ){
                if((rear+1)%size != front){
                    if(rear == -1 && front == -1){
                        rear = 0;
                        front = 0;
                    }else{
                        rear = (rear +1) % size;
                    }
                    values[rear] = v;
                }else{
                    throw range_error("Queue is full");
                }
            }
        }
        T deQueue(){
            if(size>0){
                if((rear == -1 && front == -1 )|| front > rear )
                {
                    throw range_error("Queue empty");
                }else{
                    T ret = values[front];
                    front = (front+1)%size;
                    return ret;
                }
            }
        }
};

enum Choice{
    EN,
    DE,
    EXIT
};

int main(){

    Choice choice = EN;
    Q<int> q(5);
    int i = 0;
    while(choice != EXIT){
        if(choice == EN){
            q.enQueue(i);
        }else{
            cout << q.deQueue() << endl;
        }
        cout << "command" << endl;
        char ch;
        cin >> ch;
        choice = ch == 'e' ? EN : ch == 'd'? DE : EXIT;
    }

}