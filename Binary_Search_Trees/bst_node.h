#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = right = NULL;
        }
};

void insertToBST(Node* &root, int d){

    Node* node = new Node(d);

    if(root == NULL){
        root = node;
        return;
    }
    if(d <= root->data){
        if(root->left != NULL){
            insertToBST(root->left, d);
            return;
        }
        root->left = node;
    }else{
        if(root->right != NULL){
            insertToBST(root->right, d);
            return;
        }
        root->right = node;
    }
}

bool search(Node* root, int key){

    if(root == NULL){
        return false;
    }
    if(key == root->data){
        return true;
    }else if(key < root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* createBST(vector<int> v){
    
    Node* root = NULL;
    for(auto val : v){
        insertToBST(root, val);
    }
    return root;
}

void prepareLevelWise(Node* root, map<int,vector<int>> &m, int level){
    if(root == NULL){
        return;
    }
    m[level].push_back(root->data);
    prepareLevelWise(root->left, m, level+1);
    prepareLevelWise(root->right, m, level+1);
}

void levelPrint(Node* root){

    map<int,vector<int>> m;
    prepareLevelWise(root, m, 0);
    for(auto p : m){
        for(auto val : p.second){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}