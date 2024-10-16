#include "../linkedlist_node.h"

int findKthLast(Node<int> *head, int k)
{

    Node<int> *curr = head;
    Node<int> *kAhead = head;

    int i = 1;
    while (i <= k)
    {
        kAhead = kAhead->next;
        i++;
    }

    while (kAhead != NULL)
    {
        curr = curr->next;
        kAhead = kAhead->next;
    }

    return curr->data;
}

int main()
{

    LinkedList<int> list;
    list.insert(70);
    list.insert(20);
    list.insert(30);
    list.insert(60);
    list.insert(50);
    list.insert(40);
    list.insert(10);
    list.insert(80);
    list.insert(90);

    cout << "List : ";
    list.print();

    int k = 3;
    cout << k << "th last : " << findKthLast(list.getHead(), k);
}