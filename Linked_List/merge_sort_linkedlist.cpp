#include "linkedlist_node.h"

Node<int> *findMid(Node<int> *head)
{

    Node<int> *slo = head;
    Node<int> *fst = head->next->next;

    while (fst != NULL and fst->next != NULL)
    {
        slo = slo->next;
        fst = fst->next->next;
    }

    return slo;
}

Node<int> *mergeRecursive(Node<int> *head1, Node<int> *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node<int> *node = NULL;
    if (head1->data <= head2->data)
    {
        node = new Node(head1->data);
        node->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        node = new Node(head2->data);
        node->next = mergeRecursive(head1, head2->next);
    }
    return node;
}

Node<int> *mergeSort(Node<int> *head)
{

    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node<int> *mid = findMid(head);
    Node<int> *head2 = mid->next;
    mid->next = NULL;
    Node<int> *firstHead = mergeSort(head);
    Node<int> *secondHead = mergeSort(head2);
    return mergeRecursive(firstHead, secondHead);
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
    cout << "List before sort : ";
    list.print();
    Node<int> *hed = mergeSort(list.getHead());
    cout << "Merge Sort Result" << endl;
    printLinkedList(hed);
}