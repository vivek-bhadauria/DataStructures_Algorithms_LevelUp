#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printSubSets(string s, string &r, int i, vector<string> &v){
    if(i==s.length()){
        v.push_back(r);
        return;
    }

    /* pick */
    r.push_back(s[i]);
    printSubSets(s,r,i+1,v);
    r.pop_back();

    /* do not pick */
    printSubSets(s,r,i+1,v);
}

int main(){

    string s,r;
    vector<string> v;
    getline(cin,s);
    printSubSets(s,r,0,v);
    cout<<"Subsets"<<endl;
    for(auto val : v){
        cout<<val<<endl;
    }
}