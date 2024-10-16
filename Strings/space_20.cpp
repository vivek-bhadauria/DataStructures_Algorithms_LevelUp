#include<iostream>
#include<string>
#include<vector>
using namespace std;

string replaceSpace(string s, string x){

    int c=0;
    int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i] == ' '){
            c++;
        }
    }
    int a = (x.length()-1)*c;
    for(int i=1; i<=a; i++){
        s.push_back('_');
    }

    int f = n+a-1;
    int l = n-1;
    while(l>=0){
        if(s[l] == ' '){
            int k = x.length()-1;
            while(k>=0){
                s[f] = x[k];
                f--;
                k--;
            }
            l--;
        }else{
            s[f] = s[l];
            f--;
            l--;
        }
    }
    s.push_back('\0');
    return s;
}

vector<string> tokenize(string s, char ch){

    vector<string> res;
    string x;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ch){
            x.push_back('\0');
            res.push_back(x);
            x.clear();
        }else{
            x.push_back(s[i]);
        }
    }
    x.push_back('\0');
    res.push_back(x);
    return res;
}

int main(){

    string s = "Hello, how are you?";
    cout<<"input = "<<s<<endl;
    s = replaceSpace(s, "%20");
    cout<<"S = "<<s<<endl;

    string s1 = "what a lovely day it is today";
    cout<<"input = "<<s1<<endl;
    vector<string> x = tokenize(s1, ' ');
    for(auto val : x){
        cout<<val<<endl;
    }

}