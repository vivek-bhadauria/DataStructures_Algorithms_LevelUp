#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node<T>(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head;

public:
    LinkedList<T>()
    {
        head = NULL;
    }

    Node<T> *getHead()
    {
        return head;
    }

    void insert(T data)
    {
        Node<T> *node = new Node<T>(data);
        node->next = head;
        head = node;
    }

    void print()
    {
        Node<T> *p = head;
        while (p != NULL)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << endl;
    }
};

template <typename T>
void printLinkedList(Node<T> *head)
{
    Node<T> *p = head;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << endl;
}