#include <iostream>
#include <vector>
#include "dp_helper.h"
using namespace std;

int maxNonAdjSumTD(vector<int> v, int n, vector<int> &cache)
{
    if (n == 0)
    {
        cache[n] = 0;
        return cache[n];
    }
    if (n == 1)
    {
        cache[n] = max(0, v[n - 1]);
        return cache[n];
    }
    if (n == 2)
    {
        cache[n] = max(0, max(v[n - 1], v[n - 2]));
        return cache[n];
    }
    if (cache[n] != 0)
    {
        return cache[n];
    }

    cache[n] = max(v[n - 1] + maxNonAdjSumTD(v, n - 2, cache), maxNonAdjSumTD(v, n - 1, cache));
    return cache[n];
}

int maxNonAdjSumBU(vector<int> v, int n, vector<int> &cache)
{
    cache[0] = 0;
    cache[1] = max(0, v[0]);
    cache[2] = max(0, max(v[1], v[0]));

    for (int i = 3; i <= n; i++)
    {
        cache[i] = max(v[i - 1] + cache[i - 2], cache[i - 1]);
    }
    return cache[n];
}

void printChoices(vector<int> v, vector<int> cache)
{
    int i = v.size();
    cout << "Choices : ";
    while (i >= 0)
    {
        if (v[i - 1] + cache[i - 2] > cache[i - 1])
        {
            cout << v[i - 1] << " ";
            i = i - 2;
        }
        else
        {
            i = i - 1;
        }
    }
    cout << endl;
}

int main()
{

    vector<int> v = {6, 10, 12, 7, 9, 14};
    int n = v.size();

    /* Testing the top down approach */
    vector<int> cache(n + 1, 0);
    int res = maxNonAdjSumTD(v, n, cache);
    cout << "Result : " << res << endl;
    printChoices(v, cache);

    /* Testing the bottom up approach */
    vector<int> cache1(n + 1, 0);
    int res2 = maxNonAdjSumBU(v, n, cache1);
    cout << "Result2 : " << res2 << endl;
    printChoices(v, cache1);
}