#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string findMaxUniqueString(string s){
    int i=0;
    int j=0;
    int n=s.length();
    int start=-1;
    int max_str_len=INT_MIN;
    unordered_map<char,int> h;


    while(j<n){
        char ch=s[j];
        if(h.find(ch) != h.end() and h[ch]>=i){
            i=h[ch]+1;
        }
        h[ch]=j;
        if((j-i+1)>max_str_len){
            start=i;
            max_str_len=j-i+1;
        }
        j++;
    }
    return s.substr(start,max_str_len);
}

int main(){

    string s;
    getline(cin,s);
    string result = findMaxUniqueString(s);
    cout<<"Result = "<<result<<endl;

}