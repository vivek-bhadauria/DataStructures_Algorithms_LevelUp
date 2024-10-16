#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a, string b){
    return a + b < b + a;
}

string smallestString(vector<string> v){

    string res;
    sort(v.begin(), v.end(), compare);
    for(auto val : v){
        res += val;
    }
    return res;
}

int main(){

    vector<string> v = {"a", "ab", "aba"};
    cout<<"Result = "<<smallestString(v)<<endl;

}