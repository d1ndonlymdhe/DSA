#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Q
{
  T *values;
  int front = -1;
  int rear = -1;
  int max = 0;

public:
  Q(int max)
  {
    this->max = max;
    values = (T *)(calloc(max, sizeof(T)));
  }
  bool isFull()
  {
    return rear == max - 1;
  }
  bool isEmpty()
  {
    return (rear == -1 && front == -1) || rear < front;
  }
  void enQ(T v)
  {
    if (!isFull())
    {
      rear++;
      if (front == -1)
      {
        front++;
      }
      values[rear] = v;
    }
    else
    {
      throw out_of_range("Queue full");
    }
  }
  T deQ()
  {
    if (!isEmpty())
    {
      T v = values[front];
      front++;
      return v;
    }
    else
    {
      throw out_of_range("Queue empty");
    }
  }
};

int main()
{
  Q<int> q(10);
  for (int i = 0; i < 6; i++)
  {
    q.enQ(i);
  }
  for (int i = 0; i < 10; i++)
  {
    cout << q.deQ() << endl;
  }
  return 0;
}