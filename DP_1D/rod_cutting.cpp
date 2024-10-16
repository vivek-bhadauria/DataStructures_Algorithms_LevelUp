#include <iostream>
#include <vector>
#include "dp_helper.h"
using namespace std;

int maxProfitHelper(vector<int> prices, int n, vector<int> &cache, vector<int> &choices)
{
    if (n == 0)
    {
        cache[n] = 0;
        return cache[n];
    }
    if (n < 0)
    {
        return -1;
    }
    if (cache[n] != INT_MIN)
    {
        return cache[n];
    }
    int max_profit = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        int curr_profit = maxProfitHelper(prices, n - i, cache, choices);
        if (curr_profit != -1 and prices[i] + curr_profit > max_profit)
        {
            max_profit = prices[i] + curr_profit;
            choices[n] = i;
        }
    }
    cache[n] = max_profit == INT_MIN ? -1 : max_profit;
    return cache[n];
}

/* Printing cuts done to reach maximum profit */
void printCuts(vector<int> prices, vector<int> choices, int n)
{
    cout << "Cuts : " << endl;
    while (n > 0)
    {
        int len = choices[n];
        int price = prices[len];
        cout << "Cut length : " << len << " for gain : " << price << endl;
        n = n - len;
    }
}

int maxProfitTD(vector<int> prices, int n)
{
    vector<int> cache(n + 1, INT_MIN);
    vector<int> choices(n + 1, -1);
    int max_profit = maxProfitHelper(prices, n, cache, choices);
    printCuts(prices, choices, n);
    return max_profit;
}

/*
Time Complexity : O(N^2)
Space Complexity : O(N)
*/
int maxProfitBU(vector<int> prices, int n)
{
    vector<int> cache(n + 1, INT_MIN);
    int n1 = prices.size();
    cache[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int max_profit = INT_MIN;
        for (int j = 1; j < n1; j++)
        {
            if (i - j >= 0 and cache[i - j] != -1 and prices[j] + cache[i - j] > max_profit)
            {
                max_profit = prices[j] + cache[i - j];
            }
        }
        cache[i] = max_profit == INT_MIN ? -1 : max_profit;
    }
    return cache[n];
}

int main()
{
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cin >> n;
    int res = maxProfitTD(prices, n);
    cout << "Result : " << res << endl;
    int res2 = maxProfitBU(prices, n);
    cout << "Result2 : " << res2 << endl;
}