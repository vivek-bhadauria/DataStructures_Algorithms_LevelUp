#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> v, int key){
    int n=v.size();
    int s=0;
    int e=n-1;
    int m=-1;

    while(s<=e){
        m=(s+e)>>1;
        if(m>0 and m<n-1 and v[m]<v[m-1] and v[m]<v[m+1]){
            return m;
        }else if(v[m] < v[s]){
            e=m-1;
        }else{
            s=m+1;
        }
    }
    return -1;
}

int rotateSearchWithPivot(vector<int> v, int key){

    int s=0;
    int e=v.size()-1;
    int m=-1;
    int p = findPivot(v,key);
    if(key == v[p]){
        return p;
    }else if(key <= v[e]){
        s=p+1;
    }else{
        e=p-1;
    }
    /* perform regular binary search */
    while(s<=e){
        m=(s+e)>>1;
        if(key == v[m]){
            return m;
        }else if(key < v[m]){
            e=m-1;
        }else{
            s=m+1;
        } 
    }
    return -1;
}

int rotateSearchWithOutPivot(vector<int> v, int key){
    int n=v.size();
    int s=0;
    int e=n-1;
    int m=-1;

    while(s<=e){
        m=(s+e)>>1;
        if(key == v[m]){
            return m;
        }else if(v[s] <= v[m]){
            if(key>=v[s] and key<=v[m]){
                e=m-1;
            }else{
                s=m+1;
            }
        }else if(v[m] <= v[e]){
            if(key>=v[m] and key <=v[e]){
                s=m+1;
            }else{
                e=m-1;
            }
        }
    }
    return -1;
}

int main(){
    int key;
    vector<int> v = {7,9,10,1,2,3,4,5,6};
    cin>>key;
    int res= rotateSearchWithPivot(v,key);
    cout<<"Result = "<<res<<endl;
    int res1 = rotateSearchWithOutPivot(v, key);
    cout<<"Result1 = "<<res1<<endl;
}