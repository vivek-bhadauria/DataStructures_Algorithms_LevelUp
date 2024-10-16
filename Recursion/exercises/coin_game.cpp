#include<iostream>
#include<vector>
using namespace std;

int maxCoinValue(vector<int> v, int i, int j, vector<vector<int>> &cache){
    if(i>j){
        return 0;
    }
    if(cache[i][j]!=0){
        return cache[i][j];
    }
    /* Oswald chooses left */
    int left = v[i]+min(maxCoinValue(v,i+2,j,cache), maxCoinValue(v,i+1,j-1,cache));
    /* Oswald chooses right */
    int right = v[j]+min(maxCoinValue(v,i+1,j-1,cache), maxCoinValue(v,i,j-2,cache));
    
    cache[i][j] = max(left, right);
    return cache[i][j];
}

int maxValueDP(vector<int> v){
    int n=v.size();
    vector<vector<int>> cache(n, vector<int>(n,0));

    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            int x=INT_MAX;
            int y=INT_MAX;
            int z=INT_MAX;
            if(i+2<n){
                x = cache[i+2][j];
            }
            if(i+1<n and j-1>=0){
                y = cache[i+1][j-1];
            }
            if(j-2>=0){
                z = cache[i][j-2];
            }
            int left = min(x,y);
            int right = min(y,z);

            if(left == INT_MAX or right == INT_MAX){
                cache[i][j] = 0;
            }else{
                cache[i][j] = max(v[i] + left, v[j] + right);
            }

        }
    }

    /* print cache */
    cout<<"Cache : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cache[i][j]<<" ";
        }
        cout<<endl;
    }

    return cache[0][n-1];
}

int main(){

    vector<int> v = {1,2,3,4};
    int n= v.size();
    vector<vector<int>> cache(n, vector<int>(n,0));
    //int res = maxCoinValue(v, 0, v.size()-1, cache);
    int res = maxValueDP(v);
    cout<<"Result = "<<res<<endl;
}