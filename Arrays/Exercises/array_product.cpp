#include<iostream>
#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){

    int n = arr.size();
    vector<int> output(n,1);
    vector<int> nx(n,0);
    int p=1;
    nx[n-1] = arr[n-1];
    
    for(int j=n-2; j>=0; j--){
        nx[j] = arr[j] * nx[j+1];
    }

    for(int i=0; i<n-1; i++){
        output[i] = p * nx[i+1];
        p = p * arr[i]; 
    }
    output[n-1] = p;
    
    return output;
}

int main(){

     vector<int> v = {1,2,3,4,5};
     vector<int> res = productArray(v);

     cout<<"Result = ";
     for(auto x : res){
        cout<<x<<", ";
     }
     cout<<endl;
}