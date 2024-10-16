#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/* for each x,y we need to find count of points with same y and same x*/
int countTriangles(vector<vector<int>> v)
{

    unordered_map<int, int> xMap;
    unordered_map<int, int> yMap;
    int ctr = 0;

    for (auto pt : v)
    {
        int x = pt[0];
        int y = pt[1];
        xMap[x]++;
        yMap[y]++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i][0];
        int y = v[i][1];
        ctr += (xMap[x] - 1) * (yMap[y] - 1);
    }

    return ctr;
}

int main()
{

    vector<vector<int>> v = {{1, 2}, {2, 0}, {2, 2}, {2, 3}, {4, 2}};

    int res = countTriangles(v);
    cout << "Count of Triangles : " << res;
}