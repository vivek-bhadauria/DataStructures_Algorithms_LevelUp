#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> books, int m, int val){
    
    int i=0;
    int curr_sum=0;
    int n=books.size();
    while(i<n){
        curr_sum += books[i];
        if(curr_sum > val){
            m--;
            curr_sum=books[i];
        }
        i++;
    }
    return m>0;
}

int minPages(vector<int> books, int m){
    int s=INT_MIN;
    int e=0;
    for(auto x : books){
        s= max(s, x);
        e += x;
    }
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(books,m,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int m;
    vector<int> v = {10,20,30,15};
    cin>>m;
    int res = minPages(v, m);
    cout<<"Result = "<<res<<endl;
}