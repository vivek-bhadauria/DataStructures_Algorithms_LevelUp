#include <iostream>
#include <vector>
#include "../DP_1D/dp_helper.h"
using namespace std;

int maxProfitTD(vector<int> prices, int s, int e, vector<vector<int>> &cache)
{

    if (s > e)
    {
        return 0;
    }
    if (cache[s][e] != 0)
    {
        return cache[s][e];
    }

    int n = prices.size();
    int y = n - (e - s); /* year */
    int pickLeft = y * prices[s] + maxProfitTD(prices, s + 1, e, cache);
    int pickRight = y * prices[e] + maxProfitTD(prices, s, e - 1, cache);
    cache[s][e] = max(pickLeft, pickRight);

    return cache[s][e];
}

int maxProfitBU(vector<int> prices)
{
    int n = prices.size();
    vector<vector<int>> cache(n, vector<int>(n, 0));

    /* Case for only one bottle left in final year */
    for (int s = 0; s < n; s++)
    {
        cache[s][s] = n * prices[s];
    }

    for (int s = n - 2; s >= 0; s--)
    {
        for (int e = s + 1; e < n; e++)
        {
            int y = n - (e - s); /* year */
            int pickLeft = y * prices[s] + cache[s + 1][e];
            int pickRight = y * prices[e] + cache[s][e - 1];
            cache[s][e] = max(pickLeft, pickRight);
        }
    }
    return cache[0][n - 1];
}

void printSolution(vector<int> &prices, vector<vector<int>> &cache)
{
    int n = prices.size();
    int s = 0;
    int e = n - 1;
    cout << "Choices : " << endl;
    while (s <= e)
    {
        int y = n - (e - s);
        if (y * prices[s] + cache[s + 1][e] > y * prices[e] + cache[s][e - 1])
        {
            cout << prices[s] << " picked for year " << y << endl;
            s++;
        }
        else
        {
            cout << prices[e] << " picked for year " << y << endl;
            e--;
        }
    }
}

int main()
{

    vector<int> prices = {2, 3, 5, 1, 4};
    int n = prices.size();

    /* Testing Top Down Approach */
    vector<vector<int>> cache(n, vector<int>(n, 0));
    int res = maxProfitTD(prices, 0, n - 1, cache);
    cout << "Result = " << res << endl;
    display2DCache(cache);
    printSolution(prices, cache);

    /* Testing Bottom Up Approach */
    int res2 = maxProfitBU(prices);
    cout << "Result2 = " << res2 << endl;
}