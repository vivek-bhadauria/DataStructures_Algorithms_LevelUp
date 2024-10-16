#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int minCoins(vector<int> coins, int M)
{
    if (M == 0)
    {
        return 0;
    }
    if (M < 0)
    {
        return -1;
    }
    int min_coins = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int curr_coins = minCoins(coins, M - coins[i]);
        if (curr_coins != -1)
        {
            min_coins = min(min_coins, curr_coins);
        }
    }
    return min_coins == INT_MAX ? -1 : 1 + min_coins;
}

int minCoinsTDHelper(vector<int> coins, int M, vector<int> &cache, vector<int> &choiceIdxs)
{
    if (M == 0)
    {
        cache[M] = 0;
        return cache[M];
    }
    if (M < 0)
    {
        return -1;
    }
    if (cache[M] != INT_MAX)
    {
        return cache[M];
    }
    int min_coins = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int curr_coins = minCoinsTDHelper(coins, M - coins[i], cache, choiceIdxs);
        if (curr_coins != -1 and curr_coins < min_coins)
        {
            min_coins = curr_coins;
            choiceIdxs[M] = coins[i];
        }
    }
    cache[M] = min_coins == INT_MAX ? -1 : 1 + min_coins;
    return cache[M];
}

/* Printing the denominations used to reach minimum coins used */
int printCoinsUsed(vector<int> choiceIdxs, int M)
{

    cout << "Coins used : ";
    while (M > 0)
    {
        cout << choiceIdxs[M] << ", ";
        M = M - choiceIdxs[M];
    }
    cout << endl;
}

int minCoinsTD(vector<int> coins, int M)
{
    vector<int> cache(M + 1, INT_MAX);
    vector<int> choiceIdxs(M + 1, -1);
    int minCoins = minCoinsTDHelper(coins, M, cache, choiceIdxs);
    printCoinsUsed(choiceIdxs, M);
    return minCoins;
}

/*
Time Complexity : O(MN), N : no. of coins
Space Complexity : O(M)
*/
int minCoinsBU(vector<int> coins, int M)
{
    vector<int> cache(M + 1, INT_MAX);
    int n = coins.size();
    cache[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        int min_coins = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                int curr_coins = cache[i - coins[j]];
                if (curr_coins != -1)
                {
                    min_coins = min(min_coins, curr_coins);
                }
            }
        }
        cache[i] = min_coins == INT_MAX ? -1 : 1 + min_coins;
    }
    return cache[M];
}

int minCoinsBFS(vector<int> coins, int M)
{
    queue<int> q;
    unordered_set<int> visited;
    q.push(M);
    visited.insert(M);
    q.push(INT_MIN);

    int cnt = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == INT_MIN)
        {
            cnt++;
            q.push(INT_MIN);
            continue;
        }

        for (auto coinVal : coins)
        {
            if (curr - coinVal > 0 and visited.count(curr - coinVal) == 0)
            {
                q.push(curr - coinVal);
            }
            else if (curr - coinVal == 0)
            {
                cnt++;
                return cnt;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> coins = {1, 3, 7, 10};
    int M;
    cin >> M;
    // int res = minCoins(coins, M);
    // cout << "Result : " << res << endl;
    int res2 = minCoinsTD(coins, M);
    cout << "Result2 : " << res2 << endl;
    int res3 = minCoinsBU(coins, M);
    cout << "Result3 : " << res3 << endl;
    int res4 = minCoinsBFS(coins, M);
    cout << "Result4 : " << res4 << endl;
}