#include "../bst_node.h"

Node *lca(Node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > a and root->data > b)
    {
        return lca(root->left, a, b);
    }
    else if (root->data < a and root->data < b)
    {
        return lca(root->right, a, b);
    }
    return root;
}

int findDistance(Node *root, int key)
{
    if (root == NULL or key == root->data)
    {
        return 0;
    }
    if (key < root->data)
    {
        return 1 + findDistance(root->left, key);
    }
    else
    {
        return 1 + findDistance(root->right, key);
    }
}

int findShortestDistance(Node *root, int a, int b)
{
    Node *lcaNode = lca(root, a, b);
    return findDistance(lcaNode, a) + findDistance(lcaNode, b);
}

int main()
{

    int a, b;
    vector<int> v = {10, 4, 15, 2, 5, 13, 22, 1, 14};
    Node *root = createBST(v);
    cout << "Level Print" << endl;
    levelPrint(root);
    cout << "Inorder : ";
    inOrder(root);
    cout << endl;

    cin >> a >> b;
    /*
      shortestDistance(1, 4) -> 2
      shortestDistance(2, 13) -> 4
      shortestDistance(5, 14) -> 5
    */
    int ans = findShortestDistance(root, a, b);
    cout << "shortestDistance(" << a << ", " << b << ") : " << ans;
}