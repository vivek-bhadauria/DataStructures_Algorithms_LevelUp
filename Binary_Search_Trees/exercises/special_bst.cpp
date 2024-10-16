#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data)
    {
        key = data;
        left = right = parent = NULL;
    }

    void setLeft(Node *node)
    {
        this->left = node;
        node->parent = this;
    }

    void setRight(Node *node)
    {
        this->right = node;
        node->parent = this;
    }
};

Node *findInOrderSuccessor(Node *target)
{
    Node *curr = NULL;
    if (target == NULL)
    {
        return NULL;
    }
    else if (target->right != NULL)
    {
        curr = target->right;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
    }
    else
    {
        curr = target;
        while (curr != NULL and curr->key <= target->key)
        {
            curr = curr->parent;
        }
    }
    return curr;
}

int main()
{

    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *five = new Node(5);
    Node *nine = new Node(9);
    Node *twelve = new Node(12);
    Node *nineteen = new Node(19);
    Node *twentyOne = new Node(21);
    Node *twentyFive = new Node(25);
    vector<Node *> v = {one, two, three, five, nine, twelve, nineteen, twentyOne, twentyFive};

    /* tree creation */
    Node *root = five;
    five->setLeft(two);
    five->setRight(twelve);
    two->setLeft(one);
    two->setRight(three);
    twelve->setLeft(nine);
    twelve->setRight(twentyOne);
    twentyOne->setLeft(nineteen);
    twentyOne->setRight(twentyFive);

    /* testing inorder successor for each node */
    for (auto node : v)
    {
        Node *ans = findInOrderSuccessor(node);
        int ansVal = ans ? ans->key : -1;
        cout << "Inorder successor of " << node->key << " : " << ansVal << endl;
    }
}