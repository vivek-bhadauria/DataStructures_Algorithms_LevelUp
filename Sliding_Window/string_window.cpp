#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string findMinStringWindow(string s1, string s2){
    int i=0;
    int j=0;
    int n=s1.length();
    unordered_map<char,int> s;
    unordered_map<char,int> h;
    int cnt=0;
    int start=-1;
    int min_win_len=INT_MAX; 

    /*count map for small string*/
    for(auto ch : s2){
        s[ch]++;
    }

    while(j<n){
        char ch=s1[j];
        h[ch]++;

        if(s.find(ch)!=s.end() and h[ch]<=s[ch]){
            cnt++;
        }

        if(cnt == s2.length()){

            while(s.find(s1[i]) == s.end() or h[s1[i]]>s[s1[i]]){
                h[s1[i]]--;
                i++;
            }

            if((j-i+1)<min_win_len){
                start=i;
                min_win_len=j-i+1;
            }

        }

        j++;
    }
    
    if(start==-1){
        return "No matching string found";
    }
    return s1.substr(start, min_win_len);

}

int main(){
    string s1="fizzbuzz";
    string s2="fuzz";
    string res = findMinStringWindow(s1,s2);
    cout<<"Result = "<<res<<endl;

}