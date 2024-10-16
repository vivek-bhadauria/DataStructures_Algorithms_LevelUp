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

    void insertAtPos(T data, int pos)
    {
        if (pos == 0)
        {
            insert(data);
            return;
        }
        Node<T> *curr = head;
        int currPos = 1;
        while (currPos < pos and curr != NULL)
        {
            curr = curr->next;
            currPos++;
        }
        if (curr == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node<T> *node = new Node(data);
        node->next = curr->next;
        curr->next = node;
    }

    void insertAtEnd(T data)
    {
        Node<T> *curr = head;
        if (curr == NULL)
        {
            insert(data);
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node<T> *node = new Node(data);
        curr->next = node;
    }

    void deleteAtFront()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<T> *curr = head;
        head = curr->next;
        curr->next = NULL;
        delete curr;
    }

    void deleteAtPos(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos == 0)
        {
            deleteAtFront();
            return;
        }
        Node<T> *curr = head;
        int currPos = 1;
        while (currPos < pos and curr != NULL)
        {
            curr = curr->next;
            currPos++;
        }
        if (curr == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node<T> *delNode = curr->next;
        curr->next = delNode->next;
        delNode->next = NULL;
        delete delNode;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        Node<T> *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        Node<T> *delNode = curr->next;
        curr->next = NULL;
        delete delNode;
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

    void insertAtMiddle(T data)
    {
        Node<T> *p = head;
        Node<T> *q = head->next;

        while (q != NULL)
        {
            q = q->next;
            if (q != NULL)
            {
                q = q->next;
            }
            p = p->next;
        }

        Node<T> *node = new Node<T>(p->data);
        p->data = data;
        node->next = p->next;
        p->next = node;
    }

    void reverse()
    {
        Node<T> *first = head;
        Node<T> *second = first->next;
        first->next = NULL;
        while (second != NULL)
        {
            Node<T> *third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        head = first;
    }

    void reverseRecursive()
    {
        reverseRecursiveHelper(head, head->next);
    }

    void reverseRecursiveHelper(Node<T> *first, Node<T> *second)
    {

        if (second == NULL)
        {
            head = first;
            return;
        }
        if (first == head)
        {
            first->next = NULL;
        }
        Node<T> *third = second->next;
        second->next = first;
        reverseRecursiveHelper(second, third);
    }

    void reverseK(int k)
    {

        Node<T> *first = head;
        Node<T> *second = first->next;
        Node<T> *last = first;
        Node<T> *prevLast = first;
        Node<T> *third = NULL;
        while (first != NULL)
        {
            int c = 1;
            while (c < k and second != NULL)
            {
                third = second->next;
                second->next = first;
                first = second;
                second = third;
                c++;
            }
            if (last == head)
            {
                head = first;
            }
            else
            {
                prevLast->next = first;
                prevLast = last;
            }
            first = second;
            if (first != NULL)
            {
                second = first->next;
            }
            else
            {
                second = NULL;
                prevLast->next = first;
            }
            last = first;
        }
    }
};

int main()
{

    LinkedList<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.insert(70);
    list.insert(80);
    list.print();

    list.insertAtEnd(90);
    cout << "After inserting at end" << endl;
    list.print();

    list.insertAtPos(100, 4);
    cout << "After inserting at 4" << endl;
    list.print();

    list.deleteAtFront();
    cout << "After deleting at front" << endl;
    list.print();

    list.deleteAtPos(4);
    cout << "After deleting at 4" << endl;
    list.print();

    list.deleteAtEnd();
    cout << "After deleting at end" << endl;
    list.print();

    list.insertAtMiddle(35);
    cout << "After inserting at the middle" << endl;
    list.print();

    list.reverse();
    cout << "After Reverse" << endl;
    list.print();

    list.reverseRecursive();
    cout << "After Reversing again" << endl;
    list.print();

    list.reverseK(3);
    cout << "After reverse K" << endl;
    list.print();
}