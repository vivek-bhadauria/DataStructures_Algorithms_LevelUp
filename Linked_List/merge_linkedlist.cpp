#include "linkedlist_node.h"

Node<int> *merge(LinkedList<int> list1, LinkedList<int> list2)
{

    Node<int> *curr1 = list1.getHead();
    Node<int> *curr2 = list2.getHead();
    Node<int> *prev1 = NULL;
    Node<int> *prev2 = NULL;
    Node<int> *start1 = NULL;
    Node<int> *start2 = NULL;
    Node<int> *end1 = NULL;
    Node<int> *end2 = NULL;
    while (curr1 != NULL and curr2 != NULL)
    {

        if (curr1->data < curr2->data)
        {
            prev1 = curr1;
            curr1 = curr1->next;
            start2 = curr2;
            end2 = curr2;
            while (curr1 != NULL and curr2 != NULL and curr2->data < curr1->data)
            {
                end2 = curr2;
                curr2 = curr2->next;
            }
            while (end2 == curr2 and curr1 != NULL and curr2 != NULL and curr1->data < curr2->data)
            {
                end1 = curr1;
                curr1 = curr1->next;
            }
            if (end1 != curr1)
            {
                prev1->next = start2;
                end2->next = curr1;
            }
            else
            {
                end1->next = curr2;
            }
        }
        else if (curr2->data < curr1->data)
        {
            prev2 = curr2;
            curr2 = curr2->next;
            start1 = curr1;
            end1 = curr1;
            while (curr1 != NULL and curr2 != NULL and curr1->data < curr2->data)
            {
                end1 = curr1;
                curr1 = curr1->next;
            }
            while (end1 == curr1 and curr1 != NULL and curr2 != NULL and curr2->data < curr1->data)
            {
                end2 = curr2;
                curr2 = curr2->next;
            }
            if (end1 != curr1)
            {
                prev2->next = start1;
                end1->next = curr2;
            }
            else
            {
                end2->next = curr1;
            }
        }
        else
        {
            prev1 = curr1;
            curr1 = curr1->next;
            prev1->next = curr2;
        }
    }

    if (list1.getHead()->data <= list2.getHead()->data)
    {
        return list1.getHead();
    }
    else
    {
        return list2.getHead();
    }
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

int main()
{

    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.insert(10);
    list1.insert(7);
    list1.insert(5);
    list1.insert(1);

    list2.insert(6);
    list2.insert(5);
    list2.insert(3);
    list2.insert(2);

    cout << "List1" << endl;
    list1.print();
    cout << "List2" << endl;
    list2.print();

    // Node<int>* hd = merge(list1,list2);
    Node<int> *hd = mergeRecursive(list1.getHead(), list2.getHead());
    cout << "Merge Result Recursive" << endl;
    printLinkedList(hd);
}