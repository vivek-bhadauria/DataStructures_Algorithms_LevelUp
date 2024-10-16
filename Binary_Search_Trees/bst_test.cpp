#include "bst_node.h"
#include<string>

string toString(bool val){
    return val ? "YES" : "NO";
}

int main(){

    vector<int> v = {7, 6, 1, 10, 12, 11, 8, 2, 9};
    Node* root = createBST(v);
    
    cout<<"Inorder : ";
    inOrder(root);
    cout<<endl;

    insertToBST(root,5);
    cout<<"Inorder after inserting 5 : ";
    inOrder(root);
    cout<<endl;

    insertToBST(root, 18);
    insertToBST(root, 15);
    cout<<"Inorder after inserting 18,15 : ";
    inOrder(root);
    cout<<endl;

    cout<<"Found 3 ? "<<toString(search(root,3))<<endl;
    cout<<"Found 12 ? "<<toString(search(root,12))<<endl;

}