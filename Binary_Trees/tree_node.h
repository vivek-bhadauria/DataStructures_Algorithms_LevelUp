#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class Node{
    public: 
        T data;
        Node<T>* left;
        Node<T>* right;

        Node(T d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node<int>* buildTreeLevel(){

    int data;
    queue<Node<int>*> q;
    cin>>data;
    Node<int>* root = new Node(data);
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node<int>* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            int left, right;
            cin>>left;
            if(left != -1){
                curr->left = new Node(left);
                q.push(curr->left);
            }
            cin>>right;
            if(right != -1){
                curr->right = new Node(right);
                q.push(curr->right);
            }
        }
    }

    return root;
}

void levelPrint(Node<int>* root){

    queue<Node<int>*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node<int>* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<curr->data<<" ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}