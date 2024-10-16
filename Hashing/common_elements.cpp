#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    unordered_set<int> s;
    vector<int> res;

    for(auto val : v1){
        s.insert(val);
    }

    for(auto val : v2){
        if(s.find(val) != s.end()){
            res.push_back(val);
        }
    }

    return res;
}

int main(){
    vector<int> v1 = {1, 45, 54, 71, 76, 12};
    vector<int> v2 = {1, 7, 5, 4, 6, 12};

    cout<<"Common Elements : ";
    vector<int> res = commonElements(v1, v2);
    for(auto val : res){
        cout<<val<<" ";
    }
}