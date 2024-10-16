#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    int cs=0,cnt=0;
    unordered_map<int,int> h;
    for(int i=0; i<arr.size(); i++){
        cs += arr[i];
        if(cs == k){
            cnt++;
        }
        if(h.find(cs-k) != h.end()){
            cnt += h[cs-k];
        }
        h[cs]++;
    }
    return cnt;
}

int main(){

    vector<int> v = {10,2,-2,-20,10};
    int k=-10;
    int res = cntSubarrays(v,k);
    cout<<"Result = "<<res<<endl;
}