#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

bool isOverlapping(pair<int,int> a, pair<int,int> b){
    return !(a.first >= b.second || a.second <= b.first);
}

int countActivites(vector<pair<int,int> > activities){
    int n=activities.size();
    int pick_idx=0;
    int ctr=1;
    sort(activities.begin(), activities.end(), compare);

    for(int i=1; i<n; i++){
        if(!isOverlapping(activities[i], activities[pick_idx])){
            pick_idx = i;
            ctr++;
        }
    }
    
    return ctr;
    
}

int main(){

    vector<pair<int,int>> v = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    int res = countActivites(v);
    cout<<"Result = "<<res<<endl;

}