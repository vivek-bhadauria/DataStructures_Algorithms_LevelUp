#include <iostream>
#include <vector>
#include "dp_helper.h"
using namespace std;

int frogMinCost(vector<int> v, int n, vector<int> &cache, vector<int> &choice)
{
    if (n == 1)
    {
        cache[n] = 0;
        return cache[n];
    }
    if (n == 2)
    {
        cache[n] = abs(v[2] - v[1]);
        choice[n] = 1;
        return cache[n];
    }
    if (cache[n] != -1)
    {
        return cache[n];
    }

    int costJumpSize1 = abs(v[n] - v[n - 1]) + frogMinCost(v, n - 1, cache, choice);
    int costJumpSize2 = abs(v[n] - v[n - 2]) + frogMinCost(v, n - 2, cache, choice);

    cache[n] = min(costJumpSize1, costJumpSize2);
    if (costJumpSize1 < costJumpSize2)
    {
        cache[n] = costJumpSize1;
        choice[n] = n - 1;
    }
    else
    {
        cache[n] = costJumpSize2;
        choice[n] = n - 2;
    }

    return cache[n];
}

int frogMinCostBU(vector<int> v, int n, vector<int> &cache, vector<int> &choice)
{
    cache[1] = 0;
    cache[2] = abs(v[2] - v[1]);
    choice[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        int cost1 = abs(v[i] - v[i - 1]) + cache[i - 1];
        int cost2 = abs(v[i] - v[i - 2]) + cache[i - 2];
        if (cost1 < cost2)
        {
            cache[i] = cost1;
            choice[i] = i - 1;
        }
        else
        {
            cache[i] = cost2;
            choice[i] = i - 2;
        }
    }

    return cache[n];
}

void printPathRecursive(vector<int> choice, int n)
{
    if (n == 1)
    {
        cout << n;
        return;
    }
    if (n < 1)
    {
        return;
    }
    printPathRecursive(choice, choice[n]);
    cout << " --> " << n;
}

void printPath(vector<int> choice, int n)
{
    int i = n;
    cout << "Path : ";
    while (i > 0)
    {
        cout << i << " <-- ";
        i = choice[i];
    }
    cout << endl;
}

int main()
{

    vector<int> v = {-1, 30, 10, 60, 10, 60, 50};
    // vector<int> v = {-1, 10, 30, 40, 20};
    int n = v.size();
    vector<int> cache(n + 1, -1);
    vector<int> choice(n + 1, 0);
    vector<int> cache1(n + 1, -1);
    vector<int> choice1(n + 1, 0);

    /* Test top down approach */
    int res = frogMinCost(v, n - 1, cache, choice);
    cout << "Result : " << res << endl;
    printPath(choice, n - 1);
    cout << "Path Recursive : ";
    printPathRecursive(choice, n - 1);
    cout << endl;

    /* Test bottom up approach */
    int res2 = frogMinCostBU(v, n - 1, cache1, choice1);
    cout << "Result2 : " << res2 << endl;
    printPath(choice1, n - 1);
    cout << "Path Recursive : ";
    printPathRecursive(choice1, n - 1);
}