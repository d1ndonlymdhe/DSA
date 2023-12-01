#include <iostream>
using namespace std;

class Queue
{
protected:
  int *val;
  int front = -1;
  int rear = -1;
  int size = 0;

public:
  Queue(int size)
  {
    val = (int *)(calloc(size, sizeof(int)));
    this->size = size;
  }
  bool isFull() { return rear + 1 == size; }
  bool isEmpty() { return (front == -1 && rear == -1) || front > rear; }

  void push_back(int v)
  {
    if (!isFull())
    {
      if (front == -1 && rear == -1)
      {
        front = 0;
        rear = 0;
      }
      else
      {
        rear++;
      }
      val[rear] = v;
    }
    else
    {
      throw range_error("queue is full");
    }
  }

  int pop_front()
  {
    if (!isEmpty())
    {
      int ret = val[front];
      front++;
      return ret;
    }
    else
    {
      throw range_error("Queue is empty");
    }
  }

  void list_all()
  {
    cout << "listing all " << endl;
    if (!isEmpty())
    {
      for (int i = front; i <= rear; i++)
      {
        cout << val[i] << endl;
      }
    }
  }
};

class InputRestrictedQueue : virtual public Queue
{
public:
  InputRestrictedQueue(int size) : Queue(size)
  {
  }
  int pop_back()
  {
    if (!isEmpty())
    {
      int ret = val[rear];
      rear--;
      return ret;
    }
    else
    {
      throw range_error("Queue is empty");
    }
  }
};
class OutputRestrictedQueue : virtual public Queue
{
public:
  OutputRestrictedQueue(int size) : Queue(size)
  {
  }
  void push_front(int v)
  {
    if (!isFull())
    {
      if (front == -1 && rear == -1)
      {
        front = 0;
        rear = 0;
      }
      else
      {
        if (front - 1 < 0)
        {
          throw range_error("front already at 0");
        }
        else
        {

          front--;
        }
      }
      val[front] = v;
    }
    else
    {
      throw range_error("Queue is full");
    }
  }
};

class UnrestrictedQueue : public InputRestrictedQueue, public OutputRestrictedQueue
{
public:
  UnrestrictedQueue(int size) : Queue(size), InputRestrictedQueue(size), OutputRestrictedQueue(size)
  {
  }
};

int main()
{
  OutputRestrictedQueue OQ(10);
  OQ.push_front(1);
  // 1
  OQ.push_back(2);
  OQ.push_back(3);
  // 1 2 3
  OQ.pop_front();
  OQ.pop_front();
  // 3 
  OQ.push_back(7);
  OQ.push_back(8);
  // 3 7 8
  OQ.list_all();

  OQ.push_front(9);
  OQ.push_front(10);
  //10 9 3 7 8
  try{
    OQ.push_front(10);
  }
  catch (range_error &error)
  {
    cout << error.what() << endl;
  }
  OQ.list_all();


  InputRestrictedQueue IQ(10);
  IQ.push_back(1);
  IQ.push_back(2);
  IQ.push_back(3);
  // 1 2 3
  IQ.pop_back();
  IQ.pop_back();
  // 1
  IQ.push_back(6);
  IQ.push_back(7);
  // 1 6 7
  IQ.pop_front();
  IQ.pop_front();
  // 7
  IQ.list_all();

  return 0;
}