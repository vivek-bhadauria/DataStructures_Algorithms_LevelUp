#include "../bst_node.h"

Node* lca(Node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data < a and root-> data < b ){
        return lca(root->right, a, b);
    }else if(root->data > a and root->data > b){
        return lca(root->left, a, b);
    }
    return root;
}

int main(){

    int a,b;
    vector<int> v = {5, 2, 12, -4, 3, 9, 21, 19, 25};
    Node *root = createBST(v);
    cout << "Level Print" << endl;
    levelPrint(root);
    cout << "Inorder : ";
    inOrder(root);
    cout << endl;

    cin>>a>>b;
    /*
      lca(9, 25) -> 12
      lca(9, 3) -> 5
      lca(9, 12) -> 12
    */
    Node* ans = lca(root, a, b);
    int ansVal = ans ? ans->data : -1;
    cout<<"LCA("<<a<<", "<<b<<") : "<<ansVal;
}