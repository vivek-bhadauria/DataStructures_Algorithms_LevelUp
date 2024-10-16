#include<iostream>
#include<vector>
using namespace std;

void tracePath(int n, vector<vector<char>> c, vector<int> &v, int i, int j){
    int cell = n*i+j+1;
    if(cell == n*n){
        v.push_back(cell);
        return;
    }
    if(i==n or j==n or c[i][j] == 'X'){
        return;
    }
    v.push_back(cell);
    /* move right */
    tracePath(n,c,v,i, j+1);
    /* move down */
    tracePath(n,c,v,i+1,j);

     /* if solution not found by right and down paths
     then if this cell was added it should be removed */
    if(cell == v[v.size()-1]){
        v.pop_back();
    }
}

int main(){

    int n=4;
    vector<int> v;
    vector<vector<char>> c= {{'O','O','X','O'},
                            {'O','X','O','O'},
                            {'O','O','O','X'},
                            {'X','X','O','O'}};

    tracePath(n,c,v,0,0);
    for(auto x : v){
        cout<<x<<" ";
    }
}