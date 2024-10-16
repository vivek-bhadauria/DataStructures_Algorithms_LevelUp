#include "../bst_node.h"
#include <string>

class dat
{
public:
    int max;
    int min;
    bool isBST;

    dat()
    {
        max = INT_MIN;
        min = INT_MAX;
        isBST = false;
    }
};

dat isBST(Node *root)
{
    dat d;
    if (root == NULL)
    {
        d.isBST = true;
        return d;
    }
    dat leftData = isBST(root->left);
    dat rightData = isBST(root->right);

    d.max = max(root->data, max(leftData.max, rightData.max));
    d.min = min(root->data, min(leftData.min, rightData.min));
    bool isRootToLeftCheckOk = (leftData.max == INT_MIN or leftData.max <= root->data) and leftData.isBST and (root->left == NULL or root->left->data <= root->data);
    bool isRootToRightCheckOk = (rightData.min == INT_MAX or rightData.min > root->data) and rightData.isBST and (root->right == NULL or root->data < root->right->data);
    d.isBST = isRootToLeftCheckOk and isRootToRightCheckOk;
    return d;
}

int main()
{

    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *ten = new Node(10);

    /* tree 1 */
    /*Node* root = one;
    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;*/

    /*tree 2*/
    Node *root = four;
    four->left = two;
    four->right = five;
    two->left = one;
    two->right = three;
    // three->right = ten;

    dat res = isBST(root);
    string ans = res.isBST ? "YES" : "NO";
    cout << "isBST ? " << ans;
}