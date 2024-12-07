#include <iostream>
#include <vector>
#include "../../DP_1D/dp_helper.h"

long long countWaysTD(vector<int> coins, int N, int C, vector<vector<long>> &cache)
{
    if (C == 0)
    {
        cache[N][C] = 1;
        return cache[N][C];
    }
    if (N == 0)
    {
        cache[N][C] = 0;
        return cache[N][C];
    }
    if (cache[N][C] != -1)
    {
        return cache[N][C];
    }
    long long c = 0;
    if (C - coins[N - 1] >= 0)
    {
        c += countWaysTD(coins, N, C - coins[N - 1], cache); /* pick */
        c += countWaysTD(coins, N - 1, C, cache);            /* not pick */
    }
    else
    {
        c += countWaysTD(coins, N - 1, C, cache); /* not pick */
    }
    cache[N][C] = c;
    return cache[N][C];
}

long long countWaysBU(vector<int> coins, int C)
{
    int N = coins.size();
    vector<vector<long long>> cache(N + 1, vector<long long>(C + 1, -1));

    for (int n = 0; n <= N; n++)
    {
        cache[n][0] = 1;
    }

    for (int c = 0; c <= C; c++)
    {
        cache[0][c] = 0;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int c = 1; c <= C; c++)
        {
            if (c - coins[n - 1] >= 0)
            {
                cache[n][c] = cache[n][c - coins[n - 1]] + cache[n - 1][c];
            }
            else
            {
                cache[n][c] = cache[n - 1][c];
            }
        }
    }
    return cache[N][C];
}

int main()
{
    int C = 4;
    vector<int> coins = {1, 2, 3};
    int N = coins.size();
    vector<vector<long>> cache(N + 1, vector<long>(C + 1, -1));
    long res = countWaysTD(coins, N, C, cache);
    cout << "Result : " << res << endl;

    long res2 = countWaysBU(coins, C);
    cout << "Result BU : " << res2 << endl;
}