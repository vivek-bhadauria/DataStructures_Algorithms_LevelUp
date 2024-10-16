#include<iostream>
#include<vector>
#include<string>
using namespace std;

int sparseSearch(vector<string> v, string key){
    int i=0;
    int j=v.size()-1;
    int m=-1, l=-1, r=-1;

    while(i<=j){
        m=(i+j)>>1;

        /*in case of blank at mid traverse both sides of it to find first non blank and set mid to that idx*/
        if(v[m] == ""){
            l=m;
            r=m;
            while(l>=i and r<=j){
                if(v[r] != ""){
                    m=r;
                    break;
                }
                if(v[l] != ""){
                    m=l;
                    break;
                }
                r++;
                l--;
            }
        }

        if(v[m] == key){
            return m;
        }
        if(key < v[m]){
            j=m-1;
        }else{
            i=m+1;
        }
    }

    return -1;
}

int main(){
    
    string key;
    vector<string> v = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
    getline(cin, key);
    int res = sparseSearch(v, key);
    cout<<"Result = "<<res<<endl;
}