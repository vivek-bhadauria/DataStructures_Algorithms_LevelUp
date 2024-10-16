#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int f=-1, s=-1;
    int minDiff = INT_MAX;
    int i=0, j=0;
    int n=a.size();
    int m=b.size();

    while(i<n and j<m){
        int currDiff = a[i] - b[j];
        if(abs(currDiff) < minDiff){
            minDiff = abs(currDiff);
            f=i;
            s=j;
        }
        if(minDiff == 0){
            return {a[f],b[s]};
        }
        if(currDiff < 0){
            i++;
        }else{
            j++;
        }
    }

    return {a[f],b[s]};

}

int main(){

    vector<int> v1 = {23, 5, 10, 17, 30};
    vector<int> v2 = {26, 134, 135, 14, 19};

    pair<int,int> res = minDifference(v1, v2); 
    cout<<"Result = "<<res.first<<", "<<res.second<<endl;
}