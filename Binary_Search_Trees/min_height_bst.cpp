#include "bst_node.h"
#include<algorithm>

Node* createMinHeightBST(vector<int> v, int start, int end){
    sort(v.begin(), v.end());
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* node = new Node(v[mid]);
    node->left = createMinHeightBST(v, start, mid-1);
    node->right = createMinHeightBST(v, mid+1, end);
    return node;
}

int main(){
    vector<int> v = {4, 2, 6, 1, 3, 5, 7};
    Node* root = createMinHeightBST(v, 0, v.size()-1);
    cout<<"Level Print"<<endl;
    levelPrint(root);
    cout<<"Inorder : ";
    inOrder(root);
}