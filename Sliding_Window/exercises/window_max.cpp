#include<iostream>
#include<vector>
using namespace std;

vector<int> maxInWindow(vector<int> v,int k){
    int i=0;
    int j=0;
    int mx=INT_MIN;
    int n=v.size();
    vector<int> ans;

    while(j<n){
        mx=max(mx,v[j]);

        if((j-i+1)==k){
            ans.push_back(mx);
            if(v[i] == mx and j<n-1 and mx>v[j+1]){
                int l=i;
                mx=v[l];
                while(l<=j){
                    mx=max(mx, v[l]);
                    l++;
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main(){

    vector<int> v = {1,2,3,1,4,5,2,3,6};
    int k=3;
    vector<int> res = maxInWindow(v,k);
    for(auto i : res){
        cout<<i<<", ";
    }
    cout<<endl;
}