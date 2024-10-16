#include<iostream>
#include<vector>
using namespace std;

int lowHighBound(vector<int> v, int s, int e, int key, bool isLow){
    int lowHigh=-1;
    int m=-1;
    
    while(s<=e){
        m=(s+e)>>1;

        if(key == v[m]){
            lowHigh=m;
            if(isLow){
                e=m-1;
            }else{
                s=m+1;
            }
        }else if(key < v[m]){
                e=m-1;
        }else{
            s=m+1;
        }
    }
    return lowHigh;
}

int frequencyCount(vector<int> v, int key){
    int s=0;
    int e=v.size()-1;

    int low = lowHighBound(v,s,e,key,true);
    if(low==-1){
        return 0;
    }
    int high = lowHighBound(v,s,e,key,false);
    return high-low+1;
}

int main(){

    int k;
    vector<int> v = {0,1,1,1,1,2,2,2,3,4,4,5,10};
    cin>>k;
    int res = frequencyCount(v,k);
    cout<<"Result = "<<res<<endl;

}