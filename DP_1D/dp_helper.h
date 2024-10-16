#include <iostream>
#include <vector>
using namespace std;

void display1DCache(vector<int> cache)
{
    cout << "Cache : ";
    for (auto val : cache)
    {
        cout << val << " ";
    }
    cout << endl;
}

void display2DCache(vector<vector<int>> cache)
{
    cout << "Cache : " << endl;
    for (auto row : cache)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}