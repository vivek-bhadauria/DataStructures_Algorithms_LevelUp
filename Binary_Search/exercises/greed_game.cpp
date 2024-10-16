#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> arr, int k, int val){
    
    int curr_sum=0;
    int i=0;
    while(k>0 and i<arr.size()){
        curr_sum += arr[i];
        if(curr_sum >= val){
            k--;
            curr_sum=0;
        }
        i++;
    }
    return k==0;
}

int getCoins(vector<int> arr, int k){
    int sum=0;
    for(auto x : arr){
        sum += x;
    }
    int s=arr[0];
    int e=sum;
    int ans=0;
    while(s<=e){
        int m=(s+e)/2;
        if(isPossible(arr,k,m)){
            ans=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return ans;
}

int main(){
    int k;
    vector<int> v = {1,2,3,4};
    cin>>k;
    int res = getCoins(v,k);
    cout<<"Result = "<<res<<endl;
}