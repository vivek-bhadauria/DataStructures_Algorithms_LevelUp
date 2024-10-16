#include "bst_node.h"

Node *inOrderSuccessor(Node *root, int key, Node *successor)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        if (root->right != NULL)
        {
            Node *curr = root->right;
            while (curr->left != NULL)
            {
                curr = curr->left;
            }
            return curr;
        }
        else
        {
            return successor;
        }
    }
    else if (root->data < key)
    {
        return inOrderSuccessor(root->right, key, successor);
    }
    else
    {
        /* to find minimum of values greater than key */
        return inOrderSuccessor(root->left, key, root);
    }
}

int main()
{

    vector<int> v = {4, 2, 6, 1, 3, 5, 7, 15, 10, 9, 8};
    int key;
    Node *root = createBST(v);
    cout << "Level Print" << endl;
    levelPrint(root);
    cout << "Inorder : ";
    inOrder(root);
    cout << endl;

    cin >> key;
    Node *successor = inOrderSuccessor(root, key, NULL);
    int successorValue = successor ? successor->data : -1;
    cout << "Inorder successor for " << key << " : " << successorValue;
}