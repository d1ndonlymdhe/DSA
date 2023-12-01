#include <iostream>
using namespace std;

class Q
{
  int front = -1;
  int back = -1;
  int size = 0;
  int *values = NULL;

public:
  Q(int size)
  {
    this->size = size;
    values = (int *)(calloc(size, sizeof(int)));
  }
  bool isEmpty() { return (front == -1 && back == -1) || front > back; }
  bool isFull() { return back + 1 == size; }
  void push(int v)
  {
    if (!isFull())
    {
      if (back == -1 && front == -1)
      {
        back = 0;
        front = 0;
      }
      else
      {
        back++;
      }
      values[back] = v;
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
      front++;
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
    if (!isEmpty())
    {
      for (int i = front; i <= back; i++)
      {
        cout << values[i] << endl;
      }
    }
  }
};

int main()
{
  Q q(3);
  q.push(1);
  q.push(2);
  q.push(3);
  // 1 2 3
  try
  {
    q.push(4);
  }
  catch (range_error &e)
  {
    cout << e.what() << endl;
  }
  q.pop();
  q.pop();
  // 3
  q.listAll();
  q.pop();
  try
  {

    q.pop();
  }
  catch (range_error &e)
  {
    cout << e.what() << endl;
  }
  return 0;
}