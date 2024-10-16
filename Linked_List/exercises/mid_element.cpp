#include "../linkedlist_node.h"

int findMiddle(Node<int> *head)
{

    Node<int> *slo = head;
    Node<int> *fst = head->next;

    while (fst != NULL and fst->next != NULL)
    {
        slo = slo->next;
        fst = fst->next->next;
    }

    return slo->data;
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

    cout << "Mid : " << findMiddle(list.getHead());
}