#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool compare(pair<string,int> x, pair<string,int> y){
    return x.second < y.second;
}

int badness1(vector<pair<string,int> > teams){
    int bd=0;
    sort(teams.begin(), teams.end(), compare);
    for(int i=0; i<teams.size(); i++){
        int diff = (i+1)-teams[i].second;
        if(diff<0){
            diff *= -1;
        }
        bd += diff;
    }
    return bd;
}

int badness2(vector<pair<string,int> > teams){
    int bd=0;
    int rank=1;
    unordered_map<int,int> ct;
    for(auto v : teams){
        ct[v.second]++;
    }

    for(int i=1; i<=teams.size(); i++){

        if(ct.find(i) != ct.end()){
            while(ct[i]>0){
                int diff = i-rank;
                if(diff<0){
                    diff *= -1;
                }
                bd += diff;
                rank++;
                ct[i]--;
            }
        }
    }
    return bd;
}

int main(){

    vector<pair<string,int>> v = {  {"WinOrBooze", 1},
                                    {"BallOfDuty", 2},
                                    {"WhoKnows", 2},
                                    {"BholeChature", 1},
                                    {"DCECoders", 5},
                                    {"StrangeCase", 7},
                                    {"WhoKnows", 7}};
    int res = badness2(v);
    cout<<"Result = "<<res<<endl;                                
}