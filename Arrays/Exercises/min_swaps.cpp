#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/* Time Complexity : O(NlogN)
   Space Complexity : O(N)
 */
int minSwaps(vector<int> v){

    int n=v.size();
    unordered_map<int,int> h;
    vector<int> t(v);
    sort(t.begin(), t.end());

    for(int i=0; i<n; i++){
        h[t[i]] = i;
    }

    int ctr=0;
    for(int i=0; i<n; i++){
        while(h[v[i]] != i){
            swap(v[i], v[h[v[i]]]);
            ctr++;
        }
    }
    return ctr;
}

/* cycle find approach */
int minSwapsAlt(vector<int> v){

    int ctr=0;
    int n=v.size();
    vector<int> t(v);
    vector<int> visited(n,0);
    unordered_map<int, int> h;

    sort(t.begin(), t.end());

    for(int i=0; i<n; i++){
        h[t[i]] = i;
    }

    for(int i=0; i<n; i++){
        if(visited[i] == 0 and h[v[i]] != i){
            int c=0;
            int j=i;
            while(h[v[j]] != i){
                visited[j] = 1;
                j = h[v[j]];
                c++;
            }
            ctr += c-1;
        }
    }
    return ctr;
}

int main(){

    vector<int> v = {10, 11, 5, 4, 3, 2, 1};
    vector<int> v1 = {5, 4, 3, 2, 1};

    int res = minSwaps(v);
    cout<<"Result = "<<res<<endl;

    int res1 = minSwapsAlt(v);
    cout<<"Result1 = "<<res1<<endl;
}