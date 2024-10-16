#include<iostream>
#include<vector>
using namespace std;

int countSubset(vector<int> v, int n, int x){

    if(x==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int c=0;
    /* pick */
    if(v[n-1]<=x){
        c += countSubset(v, n-1, x-v[n-1]);
    }
    /* do not pick */
    c += countSubset(v,n-1,x); 
    return c;
}

int main(){
    int s;
    vector<int> v = {1,2,3,4,5};
    cin>>s;
    int res = countSubset(v,v.size(),s);
    cout<<"Result = "<<res<<endl;
}