#include <iostream>
#include <vector>
#include "dp_helper.h"
using namespace std;

int countTreesTD(int n, vector<int> &cache)
{
    if (n == 0 or n == 1)
    {
        cache[n] = 1;
        return 1;
    }
    if (cache[n] != 0)
    {
        return cache[n];
    }
    int cnt = 0;
    for (int idx = 1; idx <= n; idx++)
    {
        cnt += countTreesTD(idx - 1, cache) * countTreesTD(n - idx, cache);
    }
    cache[n] = cnt;
    return cache[n];
}

int countTreesBU(int n)
{
    vector<int> cache(n + 1, 0);
    cache[0] = cache[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cache[i] += cache[j - 1] * cache[i - j];
        }
    }
    return cache[n];
}

int main()
{
    int n;
    cin >> n;

    /* Testing Top Down Approach */
    vector<int> cache(n + 1, 0);
    int res = countTreesTD(n, cache);
    cout << "Result = " << res << endl;

    /* Testing Bottom Up Approach */
    int res2 = countTreesBU(n);
    cout << "Result2 = " << res2 << endl;
}