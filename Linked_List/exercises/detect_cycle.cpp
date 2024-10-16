#include "../linkedlist_node.h"
#include <string>

bool containsCycle(Node<int> *head)
{

    Node<int> *slo = head;
    Node<int> *fst = head->next;

    while (fst != NULL and slo != fst and fst->next != NULL)
    {
        slo = slo->next;
        fst = fst->next->next;
    }

    if (slo == fst)
    {
        return true;
    }
    else
    {
        return false;
    }
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

    /* adds cycle for above input */
    Node<int> *head = list.getHead();
    head->next->next->next = head->next;

    string ans = containsCycle(head) ? "YES" : "NO";
    cout << "List has cycle? " << ans;
}