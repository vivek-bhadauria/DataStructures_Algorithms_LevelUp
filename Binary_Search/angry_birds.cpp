#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int> nests, int b, int dist){
    int n=nests.size();
    int i=1;
    int j=0; /* curr pos where bird is placed */
    b--; /* to accommodate placing bird at 0th pos */
    while(b>0 and i<n){
        if(nests[i] - nests[j] >= dist){
            b--;
            j=i;
        }
        i++;
    }
    return b==0;
}

int maxMinimumDistance(vector<int> nests, int b){
    int n=nests.size();
    int s=0;
    int e=nests[n-1]-nests[0];
    int m=-1;
    int ans=-1;
    while(s<=e){
        m=(s+e)/2;
        if(canPlace(nests,b,m)){
            ans=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return ans;
}

int main(){
    int b;
    vector<int> v = {1, 2, 4, 8, 9};
    cin>>b;
    sort(v.begin(), v.end());
    int res = maxMinimumDistance(v,b);
    cout<<"Result = "<<res<<endl;
}