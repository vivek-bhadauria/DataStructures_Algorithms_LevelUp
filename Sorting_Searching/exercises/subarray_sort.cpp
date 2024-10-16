#include<iostream>
#include<vector>
using namespace std;

pair<int,int> subarraySorting(vector<int> a){
    for(int i=1; i<a.size(); i++){
        if(a[i]<a[i-1]){
            int j=i-1;
            int l=i-1;
            int mx=INT_MIN;
            /* Find correct position of the number a[i] while tracking max till that point*/
            while(j>0 and a[i]<a[j]){
                mx= max(mx,a[j]);
                l=j;
                j--;
            }
            int k=i;
            int m=i;
            /* Find correct position of max tracked earlier*/
            while(k<a.size()-1 and mx>a[k]){
                m=k;
                k++;
            }
            return {l,m};
        }
    }
    return {-1,-1};
}

int main(){

    vector<int> v = {0,2,4,7,10,11,7,12,13,14,16,19,29};
    pair<int,int> res = subarraySorting(v);
    cout<<"Result = "<<res.first<<", "<<res.second<<endl;
}