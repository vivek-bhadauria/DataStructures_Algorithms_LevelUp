#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> a, vector<int> b, vector<int> &c){
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0;

    while(i<n1 and j<n2){

        if(a[i]<=b[j]){
            c.push_back(a[i]);
            i++;
        }else{
            c.push_back(b[j]);
            j++;
        }
    }

    while(i<n1){
        c.push_back(a[i]);
        i++;
    }

    while(j<n2){
        c.push_back(b[j]);
        j++;
    }
}

vector<int> mergeSort(vector<int> v, int start, int end){
    vector<int> res;
    if(start==end){
        return {v[start]};
    }
    int mid =(start+end)>>1;
    vector<int> a = mergeSort(v, start, mid);
    vector<int> b = mergeSort(v, mid+1, end);
    merge(a,b,res);
    return res;
}

int main(){

    vector<int> v = {8,1,4,7,13,10,2,3,12,11,15};
    vector<int> res;
    res = mergeSort(v,0,v.size()-1);

    for(auto val : res){
        cout<<val<<", ";
    }
    cout<<endl;
}