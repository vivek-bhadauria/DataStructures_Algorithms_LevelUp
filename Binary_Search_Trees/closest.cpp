#include "bst_node.h"

/* Pair returned has below data
   first -> found closest target value 
   second -> absolute distance with target value */
pair<int,int> findClosest(Node* root, int target){
    pair<int,int> p;
    pair<int,int> other;
    if(root == NULL){
        p.first = -1;
        p.second = INT_MAX;
        return p;
    }

    int currDiff = abs(target - root->data);
    p.first = root->data;
    p.second = currDiff; 
    
    if(currDiff == 0){
        return p;
    } 
    
    if(target < root->data){
        other = findClosest(root->left, target);
    }else{
        other = findClosest(root->right, target);
    }

    if(other.second < p.second){
        p.first = other.first;
        p.second = other.second;
    }

    return p;
}

int findClosestIterative(Node* root, int target){

    Node* curr = root;
    int minDiff = INT_MAX;
    int ans = -1;
    while(curr != NULL){
        int currDiff = abs(target - curr->data);
        if(currDiff < minDiff){
            ans = curr->data;
        }
        if(target == curr->data){
            return curr->data;
        }else if(target > curr->data){
            curr = curr->right; 
        }else{
            curr = curr->left;
        }
    }
    return ans;
}

int main(){

    vector<int> v = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node* root = createBST(v);
    cout<<"Level Print"<<endl;
    levelPrint(root);
    cout<<"Inorder : ";
    inOrder(root);
    cout<<endl;

    pair<int,int> p = findClosest(root, 16);
    cout<<"Closest to 16 : "<<p.first<<" with difference of "<<p.second<<endl;
    cout<<"Closest to 16 iterative : "<<findClosestIterative(root, 16)<<endl;

    pair<int,int> p1 = findClosest(root, 12);
    cout<<"Closest to 12 : "<<p1.first<<" with difference of "<<p1.second<<endl;
    cout<<"Closest to 12 iterative : "<<findClosestIterative(root, 12)<<endl;
}