#include "../tree_node.h"

bool equal(Node<int>* root1, Node<int>* root2){

    if(root1 == NULL and root2 == NULL){
        return true;
    }

    if(root1 == NULL and root2 != NULL){
        return false;
    }

    if(root1 != NULL and root2 == NULL){
        return false;
    }

    /* below condition is 
       root1.key equals root2.key and root1 left subtree equals root2 right subtree and so on
       or root1.key equals root2.key and root1 left subtree equals root2 left subtree */
    return root1->data == root2->data 
          and ((equal(root1->left, root2->right) and equal(root1->right, root2->left))
               or 
               (equal(root1->left, root2->left) and equal(root1->right, root2->right)) );
}

int main(){

    /* tree 1 : 6, 3, 8, 1, 7, 4, 2, -1, -1, -1, -1, 7, 1, -1, 3, -1, -1, -1, -1, -1, -1 */
    /* tree 2 : 6, 8, 3, 2, 4, 7, 1, 3, -1, 1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 */
    Node<int>* root1 = buildTreeLevel();
    cout<<"=== Level Print Tree 1 ==="<<endl;
    levelPrint(root1);
    
    Node<int>* root2 = buildTreeLevel();
    cout<<"=== Level Print Tree 2 ==="<<endl;
    levelPrint(root2);

    bool res = equal(root1, root2);
    cout<<"Result : "<<res<<endl;
}