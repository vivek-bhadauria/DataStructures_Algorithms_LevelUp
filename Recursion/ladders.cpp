#include<iostream>
#include<vector>
using namespace std;

/* Time Complexity - O(3^n) 
   Space Complexity - O(n) */
int countWaysToClimbLadder(int n){

    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return countWaysToClimbLadder(n-1) + countWaysToClimbLadder(n-2) + countWaysToClimbLadder(n-3);
}

/* DP Approach because of overlapping subproblems
   Time Complexity - O(n) 
   Space Complexity - O(n)
*/
int countWays(int n){
    vector<int> v(n+1,0);
    v[0]=1;
    for(int i=1; i<=n; i++){
        int c=0;
        if(i>=1){
            c += v[i-1];
        }
        if(i>=2){
            c += v[i-2];
        }
        if(i>=3){
            c += v[i-3];
        }
        v[i] = c;
    }

    return v[n];
}

/* DP Approach refined
   Time Complexity - O(n) 
   Space Complexity - O(1)
*/
int countWays2(int n){
    int a=1; /* var for n-3 pos */
    int b=1; /* var for n-2 pos */
    int c=2; /* var for n-1 pos */
    int res=0;
    if(n==0){
        return a;
    }else if(n==1){
        return b;
    }else if(n==2){
        return c;
    }
    for(int i=3; i<=n; i++){
        res = a+b+c;
        a=b;
        b=c;
        c=res;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int res = countWaysToClimbLadder(n);
    cout<<"Result = "<<res<<endl;
    int res1 = countWays(n);
    cout<<"Result1 = "<<res1<<endl;
    int res2 = countWays2(n);
    cout<<"Result2 = "<<res2<<endl;
}