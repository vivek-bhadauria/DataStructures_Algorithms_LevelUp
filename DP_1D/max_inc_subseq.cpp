#include <iostream>
#include <vector>
#include "dp_helper.h"
using namespace std;

int maxIncreasingSubseqTD(vector<int> v, int n, vector<int> &cache)
{

    if (n == 0)
    {
        cache[n] = 1;
        return cache[n];
    }
    if (cache[n] != INT_MIN)
    {
        return cache[n];
    }

    for (int idx = 0; idx < n; idx++)
    {
        int currIdxLen;
        if (v[n] > v[idx])
        {
            currIdxLen = 1 + maxIncreasingSubseqTD(v, idx, cache);
        }
        else
        {
            currIdxLen = maxIncreasingSubseqTD(v, idx, cache);
        }
        cache[n] = max(cache[n], currIdxLen);
    }
    return cache[n];
}

int maxIncreasingSubseqBU(vector<int> v, vector<int> &cache)
{
    cache[0] = 1;
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int currLen = v[i] > v[j] ? 1 + cache[j] : cache[j];
            cache[i] = max(cache[i], currLen);
        }
    }
    return cache[n - 1];
}

void printChoices(vector<int> v, vector<int> &cache)
{
    int i = v.size() - 1;

    cout << "Choices : ";
    int picked = -1;
    while (i >= 0 and cache[i] > 1)
    {
        if (cache[i] - cache[i - 1] == 1)
        {
            /* element at i was picked and hence increment happened */
            cout << v[i] << " ";
            picked = v[i];
        }
        i--;
    }
    while (i >= 0)
    {
        if (v[i] < picked)
        {
            cout << v[i];
            break;
        }
        i--;
    }
    cout << endl;
}

int main()
{

    vector<int> v = {50, 4, 10, 8, 30, 100, 2};
    int n = v.size();

    /* Testing top down approach */
    vector<int> cache(n, INT_MIN);
    int res = maxIncreasingSubseqTD(v, n - 1, cache);
    cout << "Result : " << res << endl;
    display1DCache(cache);
    printChoices(v, cache);

    /* Testing bttom up approach */
    vector<int> cache1(n, INT_MIN);
    int res2 = maxIncreasingSubseqBU(v, cache1);
    cout << "Result2 : " << res2 << endl;
    display1DCache(cache1);
    printChoices(v, cache1);
}