#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> findHouses(vector<int> v, int k)
{
    int n = v.size();
    int i = 0, j = 0, s = 0;
    vector<pair<int, int>> res;
    int curr_min=INT_MAX;
    int min_i=-1;
    int min_j=-1;
    while (j < n)
    {
        s += v[j];

        while (s > k)
        {
            s -= v[i];
            i++;
        }
        
        if (s == k)
        {
            res.push_back({i, j});
            if((j-i+1) < curr_min){
                curr_min = j-i+1;
                min_i=i;
                min_j=j;
            }
        }
        j++;
    }

    cout<<"Min Window is of size : "<<curr_min<<" at : "<<min_i<<", "<<min_j<<endl;
    return res;
}

/* Not correct approach */
vector<pair<int,int>> findHousesWithNegative(vector<int> v, int k){
    int n=v.size();
    int i=0,j=0;
    int min_num=INT_MAX;
    int cs=0;
    vector<pair<int,int>> ans;

    /* find minNum */
    for(int i=0; i<n; i++){
        min_num = min(min_num, v[i]);
    }

    min_num=-1*min_num;
    while(j<n){
        cs = cs + v[j] + min_num;

        while(cs > (k+(j-i+1)*min_num) and i<=j){
            cs = cs - v[i] - min_num;
            i++;
        }
        if(cs == (k+(j-i+1)*min_num)){
            ans.push_back({i,j});
        }
        j++;
    }

    return ans;

}

int main()
{
    int k;
    vector<int> v = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    cin >> k;
    vector<pair<int, int>> res = findHouses(v, k);
    vector<int> v1 = {10,2,-2,-20,10};
    vector<pair<int,int>> res1 = findHousesWithNegative(v1,k);
    for (auto p : res1)
    {
        cout << p.first << ", " << p.second << endl;
    }
    cout << endl;
}