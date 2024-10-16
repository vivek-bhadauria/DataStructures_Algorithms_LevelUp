#include<iostream>
#include<vector>
using namespace std;

int maxSubArraySum(vector<int> v){

    int n = v.size();
    int currMaxSum = INT_MIN;
    int s = 0;

    for(int i=0; i<n; i++){
        s += v[i];
        if(s<0){
            s=0;
        }
        currMaxSum = max(currMaxSum, s);
    }

    return currMaxSum;
}

int main(){

    vector<int> v = {-1,2,3,4,-2,6,-8,3};
    int res = maxSubArraySum(v);
    cout<<"Result = "<<res<<endl;
}