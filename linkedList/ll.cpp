#include <iostream>
using namespace std;
template <class T>
class Node
{

public:
  T value;
  Node<T> *next;
  Node(T value, Node<T> *next = NULL)
  {
    this->value = value;
    this->next = next;
  }
};

template <class T>
class LinkedList
{
public:
  Node<T> *head;

  LinkedList() { head = NULL; }
  LinkedList(T headValue) { head = new Node(headValue); }

  bool isEmpty() { return head == NULL; }

  Node<T> *getLast()
  {
    if (isEmpty())
    {
      return NULL;
    }
    else
    {
      Node<T> *n = head;
      while (n->next != NULL)
      {
        n = n->next;
      }
      return n;
    }
  }

  Node<T> *search(T search_value)
  {
    if (!isEmpty())
    {
      Node<T> *n = head;
      while (n->value != search_value)
      {
        if (n->next == NULL)
        {
          return NULL;
        }
        else
        {
          n = n->next;
        }
      }
      return n;
    }
    else
    {
      return NULL;
    }
  }

  void append_at_head(T value)
  {
    Node<T> *newNode = new Node(value, head);
    head = newNode;
  }
  void append_at_last(T value)
  {
    if (isEmpty())
    {
      head = new Node(value);
    }
    else
    {
      getLast()->next = new Node(value);
    }
  }
  bool append_nextto_value(T search_value, T new_value)
  {
    if (!isEmpty())
    {
      Node<T> *el = search(search_value);
      el->next = new Node(new_value, el->next);
      return true;
    }
    return false;
  }
  bool append_before_value(T search_value, T new_value)
  {
    if (!isEmpty())
    {
      Node<T> *n = head;
      while (n->next->value != search_value)
      {
        if (n->next->next == NULL)
        {
          return false;
        }
        else
        {
          n = n->next;
        }
      }
      n->next = new Node(new_value, n->next);
    }
    return false;
  }

  void delete_head()
  {
    if (!isEmpty())
    {
      Node<T> *freeThis = head;
      head = head->next;
      free(freeThis);
    }
  }
  void delete_last()
  {
    if (!isEmpty())
    {
      if (head->next == NULL)
      {
        Node<T> *freeThis = head;
        head = NULL;
        free(freeThis);
      }
      else
      {

        Node<T> *n = head;
        while (n->next->next != NULL)
        {
          n = n->next;
        }
        Node<T> *freeThis = n->next;
        n->next = NULL;
        free(freeThis);
      }
    }
  }
  bool delete_value(T search_value)
  {
    if (!isEmpty())
    {

      Node<T> *n = head;
      if (n->value == search_value)
      {
        Node<T> *freeThis = head;
        head = head->next;
        free(freeThis);
        return true;
      }
      else
      {
        while (n->next->value != search_value)
        {

          if (n->next->next == NULL)
          {
            return false;
          }
          n = n->next;
        }
        Node<T> *freeThis = n->next;
        n->next = n->next == NULL ? NULL : n->next->next;
        free(freeThis);
        return true;
      }
    }
    return false;
  }
  bool delete_nextto_value(T search_value)
  {
    if (!isEmpty())
    {
      Node<T> *el = search(search_value);
      if (el != NULL)
      {
        Node<T> *freeThis = el->next;
        Node<T> *newNext = el->next == NULL ? NULL : el->next->next;
        el->next = newNext;
        free(freeThis);
      }
    }
    return false;
  }
  bool delete_before_value(T search_value)
  {
    if (!isEmpty())
    {

      Node<T> *node1 = head;
      Node<T> *node2, *node3;
      if (node1->next == NULL)
      {
        return false;
      }
      node2 = node1->next;
      if (node2->value == search_value)
      {
        free(node1);
        head = node2;
        return true;
      }
      if (node2->next == NULL)
      {
        return false;
      }
      node3 = node2->next;
      while (node3->value != search_value)
      {
        if (node3->next == NULL)
        {
          return false;
        }
        node1 = node2;
        node2 = node3;
        node3 = node3->next;
      }
      free(node2);
      node1->next = node3;
    }
    return false;
  }

  void listAll()
  {
    cout << "---------" << endl;
    if (!isEmpty())
    {
      Node<T> *n = head;
      while (n->next != NULL)
      {
        cout << n->value << endl;
        n = n->next;
      }
      cout << n->value << endl;
    }
    cout << "--------" << endl;
  }
};
int main()
{
  LinkedList<int> ll;
  ll.append_at_last(1);
  ll.append_at_head(2);
  ll.append_at_last(3);
  ll.append_nextto_value(2, 4);
  ll.append_before_value(4, 5);
  ll.append_at_last(10);
  ll.append_at_last(11);
  ll.append_at_last(12);
  ll.listAll();

  ll.delete_head();
  ll.delete_last();
  ll.delete_nextto_value(4);
  ll.delete_before_value(4);
  ll.delete_value(4);

  ll.listAll();

  Node<int> *eleven = ll.search(11);
  if (eleven)
  {
    eleven->value = 100;
  }
  ll.listAll();
}
