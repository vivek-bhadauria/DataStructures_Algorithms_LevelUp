#include<iostream>
#include<vector>
using namespace std;

int largetPath(vector<vector<int>> v, vector<vector<int>> &visited, int rows, int cols, int i, int j){
    int max_len=-1;
    if(i==rows-1 and j==cols-1){
        return 0;
    }
    if(i>=0 and i<rows and j>=0 and j<cols and visited[i][j] == 1){
        return 0;
    }
    if(i<0 or i==rows or j<0 or j==cols or v[i][j] == 0){
        return -1;
    }
    visited[i][j]=1;
    vector<int> x={-1,0,1,0};
    vector<int> y={0,1,0,-1};
    for(int k=0; k<x.size(); k++){
        int len = 1+largetPath(v,visited,rows,cols,i+x[k],j+y[k]);
        if(len != -1){
            max_len = max(max_len, len);
        }
    }
    visited[i][j] = 0;
    return max_len;
}

int main(){
    vector<vector<int>> v = {{1,1,1},
                             {1,1,1},
                             {0,0,1}};
    vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 0));
    int res = largetPath(v, visited, v.size(), v[0].size(), 0, 0);
    cout<<"Result = "<<res<<endl;
}