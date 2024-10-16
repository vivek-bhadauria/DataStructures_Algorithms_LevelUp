#include<iostream>
#include<string>
#include<vector>
using namespace std;

string keymap(int n){

    vector<string> keys = {"", "", "ABC", "DEF", "GHI", "JKL",
    "MNO", "PQRS", "TUV", "WXYZ"};
    
    return keys[n];
}


void generateKeypadStrings(int n, string s){

    if(n==0){
        cout<<s<<endl;
        return;
    }

    string keys = keymap(n%10);
    if(keys==""){
        generateKeypadStrings(n/10, s);
    }
    for(int i=0; i<keys.length(); i++){
        generateKeypadStrings(n/10, keys[i] + s);
    }  
}

int main(){

    int n;
    string s;
    cin>>n;
    generateKeypadStrings(n,s);
    
}