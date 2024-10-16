#include<iostream>
using namespace std;

void permute(string s, string r, int i){
    if(i==s.length()){
        cout<<r<<endl;
        return;
    }

    for(int j=i; j<s.length(); j++){
        swap(s[i], s[j]);
        permute(s, r + s[i], i+1);
        swap(s[i], s[j]);
    }

}
int main(){

    string s,r;
    getline(cin,s);
    cout<<"Permutations"<<endl;
    permute(s,r,0);

}