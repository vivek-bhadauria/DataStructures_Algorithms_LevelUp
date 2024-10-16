#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int,int> minPair(vector<int> a, vector<int> b){

    sort(b.begin(), b.end());
    pair<int,int> res;
    int min_diff=INT_MAX;
    for(int i=0; i<a.size(); i++){
        int s=0;
        int e=b.size()-1;
        int minGt=INT_MAX;
        int maxLt=INT_MIN;
        int curr_diff=0;
        int min_diff_num=0;
        /* binary search to find max less than curr and min greater than curr */
        while(s<=e){
            int m=(s+e)/2;
            if(b[m] == a[i]){
                minGt=b[m];
                maxLt=b[m];
                break;
            }else if(b[m] < a[i]){
                maxLt=b[m];
                s=m+1;
            }else{
                minGt=b[m];
                e=m-1;
            }
        }
        /* find min abs diff between curr and min greater AND curr and max lesser*/
        if(abs(a[i] - maxLt) < abs(minGt - a[i])){
            curr_diff=abs(a[i] - maxLt);
            min_diff_num=maxLt;
        }else{
            curr_diff=abs(minGt - a[i]);
            min_diff_num=minGt;
        }

        /* track if curr diff is smaller than min diff*/
        if(curr_diff < min_diff){
            min_diff = curr_diff;
            res={a[i], min_diff_num};
        }
    }

    return res;
}

int main(){
    vector<int> a = {-1,5,10,20,3};
    vector<int> b = {26,134,135,15,17};

    pair<int,int> res = minPair(a,b);
    cout<<"Result = "<<res.first<<", "<<res.second<<endl;
}