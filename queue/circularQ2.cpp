#include <iostream>
using namespace std;

class circularQ
{
public:
    int front = -1;
    int rear = -1;
    int max = 0;
    int *values = 0;

    circularQ(int size)
    {
        max = size;
        values = (int *)(calloc(size, sizeof(int)));
    }
    bool isFull()
    {
        return (rear + 1) % max == front;
    }
    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }
    void push(int v)
    {
        if (!isFull())
        {
            if (rear == -1 && front == -1)
            {
                rear++;
                front++;
                values[rear] = v;
            }
            else
            {
                rear = (rear + 1) % max;
                values[rear] = v;
            }
        }
        else
        {
            throw range_error("Queue is full");
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            int ret = values[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % max;
            }
            return ret;
        }
        else
        {
            throw range_error("Queue is empty");
        }
    }
    void listAll()
    {
        cout << "listing values" << endl;
        circularQ Qcopy = *this;
        while (!Qcopy.isEmpty())
        {
            cout << Qcopy.pop() << endl;
        }
    }
};
int main()
{
    circularQ q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // 1 2 3 4
    try
    {
        q.push(5);
    }
    catch (range_error &e)
    {
        cout << e.what() << endl;
    }
    q.pop();
    q.pop();
    // 3 4
    q.push(5);
    q.push(6);
    // 3 4 5 6
    q.listAll();
    q.pop();
    // 4 5 6
    q.push(7);
    // 4 5 6 7
    q.listAll();
    return 0;
}