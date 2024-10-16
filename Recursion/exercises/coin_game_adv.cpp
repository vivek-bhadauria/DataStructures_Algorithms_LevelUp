#include<iostream>
#include<vector>
using namespace std;

int maxCoinValue(vector<int> v, int i, int j, int k){
    int n=v.size();
    if(i>j or i>=n or j<0){
        return 0;
    }
    
    /* Oswald chooses left */
    int leftSel=0;
    for(int m=0; i+m<n and m<k; m++){
        leftSel += v[i+m];
    }
    int left = leftSel + min(maxCoinValue(v,i+2*k,j,k), maxCoinValue(v,i+k,j-k,k));
    
    /* Oswald chooses right */
    int rightSel=0;
    for(int m=0; j-m>=0 and m<k; m++){
        rightSel += v[j-m];
    }
    int right = rightSel+min(maxCoinValue(v,i+k,j-k,k), maxCoinValue(v,i,j-2*k,k));
    return max(left, right);
}

int main(){

    int k;
    vector<int> v = {10, 15, 20, 9, 2, 5};
    cin>>k;
    int res = maxCoinValue(v, 0, v.size()-1, k);
    cout<<"Result = "<<res<<endl;
}