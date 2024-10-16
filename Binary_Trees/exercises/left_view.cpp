#include "../tree_node.h"
#include<map>

void leftView(Node<int>* root){

    queue<Node<int>*> q;
    q.push(root);
    q.push(NULL);
    cout<<q.front()->data<<" ";

    while(!q.empty()){
        Node<int>* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<q.front()->data<<" ";
                q.push(NULL);
            }
        }else{
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

void leftViewRecursive(Node<int>* root, int level, map<int,int> &m){

    if(root==NULL){
        return;
    }

    if(m.find(level) == m.end()){
        m[level] = root->data;
    }
    leftViewRecursive(root->left, level+1, m);
    leftViewRecursive(root->right, level+1, m);
}

void leftViewRecursiveWrapper(Node<int>* root){
     map<int,int> m;
     leftViewRecursive(root, 0, m);
     for(auto p : m){
        cout<<p.second<<" ";
     }
}

int main(){

    /* input - 1, 2, 3, -1, 4, -1, 6, -1, 5, -1, -1, -1, -1 */
    Node<int>* root = buildTreeLevel();
    cout<<"=== Level Print ==="<<endl;
    levelPrint(root);
    cout<<"Left View : ";
    leftView(root);
    cout<<endl<<"Left View Recursive : ";
    leftViewRecursiveWrapper(root);
}