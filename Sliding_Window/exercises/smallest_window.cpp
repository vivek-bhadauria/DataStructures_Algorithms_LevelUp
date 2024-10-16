#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string smallestWindow(string str){
    int i=0,j=0,cnt=0,start=-1,min_len=INT_MAX,n=str.length();
    unordered_map<char,int> s;
    unordered_map<char,int> h; //window map

    /*count map for source string*/
    for(auto v : str){
        s[v]++;
    }

    while(j<n){
        char ch=str[j];
        h[ch]++;

        if(h[ch]==1){
            cnt++;
        }

        if(cnt == s.size()){

            while(h[str[i]]>1){
                h[str[i]]--;
                i++;
            }

            if((j-i+1)<min_len){
                start=i;
                min_len=j-i+1;
            }
        }
        j++;
    }
    return str.substr(start,min_len);

}

int main(){
    string s;
    getline(cin,s);
    string result = smallestWindow(s);
    cout<<"Result = "<<result<<endl;
}