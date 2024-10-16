#include<iostream>
#include<vector>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    int i=0;
    int j=n-1;

    while(i<m and j>=0){
        if(v[i][j] == k){
            return {i,j};
        }
        if(k < v[i][j]){
            j--;
        }else{
            i++;
        }
    }

    return {-1,-1};
    
}

int main(){
    int key;
    vector<vector<int>> v = {{1, 4, 9},
                             {2, 5, 10},
                             {6, 7, 11}};
    cin>>key;
    pair<int,int> res = search(v.size(), v[0].size(), v, key);
    cout<<"Result = "<<res.first<<", "<<res.second<<endl;
}