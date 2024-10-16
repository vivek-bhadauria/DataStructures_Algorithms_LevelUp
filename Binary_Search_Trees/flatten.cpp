#include "bst_node.h"

class Pair
{
public:
    Node *head;
    Node *max;

    Pair()
    {
        head = max = NULL;
    }
};

Node *findMax(Node *root)
{
    Node *curr = root;
    if (curr == NULL)
    {
        return NULL;
    }
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}

Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *head = flatten(root->left);
    Node *predecessor = findMax(root->left);
    if (predecessor != NULL)
    {
        predecessor->right = root;
    }
    root->right = flatten(root->right);

    return head ? head : root;
}

Pair flattenOptimized(Node *root)
{
    Pair p;
    if (root == NULL)
    {
        return p;
    }

    Pair leftPair = flattenOptimized(root->left);
    if (leftPair.max != NULL)
    {
        leftPair.max->right = root;
    }
    Pair rightPair = flattenOptimized(root->right);
    root->right = rightPair.head;

    p.head = leftPair.head ? leftPair.head : root;
    p.max = rightPair.max ? rightPair.max : root;

    return p;
}

void printFlattenedTree(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main()
{

    vector<int> v = {4, 2, 6, 1, 3, 5, 7};
    Node *root = createBST(v);
    cout << "Level Print" << endl;
    levelPrint(root);
    cout << "Inorder : ";
    inOrder(root);
    cout << endl;

    // Node *head = flatten(root);
    Pair p = flattenOptimized(root);
    Node *head = p.head;

    cout << "Flattened Tree Optimized : ";
    printFlattenedTree(head);
}