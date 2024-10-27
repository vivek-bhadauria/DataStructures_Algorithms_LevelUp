#include <iostream>
#include <vector>
#include "../DP_1D/dp_helper.h"
using namespace std;

int maxProfitTD(vector<int> prices, vector<int> wts, int N, int W, vector<vector<int>> &cache)
{
    if (N == 0 or W == 0)
    {
        cache[N][W] = 0;
        return cache[N][W];
    }
    if (cache[N][W] != -1)
    {
        return cache[N][W];
    }
    if (W - wts[N - 1] >= 0)
    {
        int inc = prices[N - 1] + maxProfitTD(prices, wts, N - 1, W - wts[N - 1], cache);
        int exc = maxProfitTD(prices, wts, N - 1, W, cache);
        cache[N][W] = max(inc, exc);
    }
    else
    {
        cache[N][W] = maxProfitTD(prices, wts, N - 1, W, cache);
    }
    return cache[N][W];
}

void printChoices(vector<int> prices, vector<int> wts, vector<vector<int>> cache, int N, int W)
{

    while (N > 0 and W > 0)
    {
        if (cache[N][W] != cache[N - 1][W])
        {
            cout << "Weight : " << wts[N - 1] << " picked for Profit : " << prices[N - 1] << endl;
            W = W - wts[N - 1];
        }
        N = N - 1;
    }
}

int maxProfitBU(vector<int> prices, vector<int> wts, int N, int W)
{
    vector<vector<int>> cache(N + 1, vector<int>(W + 1, -1));

    /* init base case */
    for (int i = 0; i <= W; i++)
    {
        cache[0][i] = 0;
    }
    for (int i = 0; i <= N; i++)
    {
        cache[i][0] = 0;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (w - wts[n - 1] >= 0)
            {
                cache[n][w] = max(prices[n - 1] + cache[n - 1][w - wts[n - 1]],
                                  cache[n - 1][w]);
            }
            else
            {
                cache[n][w] = cache[n - 1][w];
            }
        }
    }
    return cache[N][W];
}

int main()
{
    int N = 4;
    int W = 11;
    vector<int> wts = {2, 7, 3, 4};
    vector<int> prices = {5, 20, 20, 10};

    vector<vector<int>> cache(N + 1, vector<int>(W + 1, -1));
    int res = maxProfitTD(prices, wts, N, W, cache);
    printChoices(prices, wts, cache, N, W);
    cout << "Result : " << res << endl;

    int res2 = maxProfitBU(prices, wts, N, W);
    cout << "Result2 : " << res2 << endl;
}