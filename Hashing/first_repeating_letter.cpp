#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

char firstRepeatingLetter(string str){

    unordered_set<char> s;
    int len = str.length();
    if(len == 0){
        return '\0';
    }
    s.insert(str[0]);
    for(int i=1; i<len; i++){
        if(s.find(str[i]) != s.end()){
            return str[i];
        }else{
            s.insert(str[i]);
        }
    }
    return '\0';
}

int main(){

    string s = "codingminutes";
    char res = firstRepeatingLetter(s);
    cout<<"First Repeating Letter : "<<res;
}