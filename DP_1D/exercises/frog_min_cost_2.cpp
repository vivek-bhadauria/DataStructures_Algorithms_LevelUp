#include <iostream>
#include <vector>
using namespace std;

long long minCostTD(vector<int> costs, int n, int k, vector<int> &cache)
{
    if (n == 0)
    {
        cache[n] = 0;
        return cache[n];
    }
    if (cache[n] != INT_MAX)
    {
        return cache[n];
    }
    long min_cost = INT_MAX;
    for (int idx = 1; idx <= k and n - idx >= 0; idx++)
    {
        long currCost = abs(costs[n] - costs[n - idx]) + minCostTD(costs, n - idx, k, cache);
        min_cost = min(min_cost, currCost);
    }
    cache[n] = min_cost;
    return cache[n];
}

long long minCostBU(vector<int> costs, int k)
{
    int n = costs.size();
    vector<int> cache(n, INT_MAX);
    cache[0] = 0;

    for (int i = 1; i < n; i++)
    {
        long min_cost = INT_MAX;
        for (int j = 1; j <= k and i - j >= 0; j++)
        {
            long currCost = abs(costs[i] - costs[i - j]) + cache[i - j];
            min_cost = min(min_cost, currCost);
        }
        cache[i] = min_cost;
    }

    return cache[n - 1];
}

int main()
{

    vector<int> stones = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int k = 5;
    int n = stones.size();

    /* Testing Top Down Approach */
    vector<int> cache(n, INT_MAX);
    int res = minCostTD(stones, n - 1, k, cache);
    cout << "Result : " << res << endl;

    /* Testing Bottom Up Approach */
    int res2 = minCostBU(stones, k);
    cout << "Result2 : " << res2 << endl;
}