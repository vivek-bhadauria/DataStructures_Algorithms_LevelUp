#include <iostream>
#include <vector>
#include "../../DP_1D/dp_helper.h"

pair<int, long long> minSmokeTD(vector<int> &colors, int s, int e, vector<vector<pair<int, long long>>> &cache)
{
    if (s == e)
    {
        return cache[s][e] = {colors[s], 0};
    }
    if (cache[s][e].first != -1 and cache[s][e].second != -1)
    {
        return cache[s][e];
    }

    pair<int, long long> minSmk = {0, LLONG_MAX};

    for (int p = s; p < e; p++)
    {
        pair<int, long long> left = minSmokeTD(colors, s, p, cache);
        pair<int, long long> right = minSmokeTD(colors, p + 1, e, cache);

        int currComp = (left.first + right.first) % 100;
        long long currSmoke = left.second + right.second + (left.first * right.first);

        if (currSmoke < minSmk.second)
        {
            minSmk = {currComp, currSmoke};
        }
    }

    return cache[s][e] = minSmk;
}

pair<int, long long> minSmokeBU(vector<int> colors)
{
    int n = colors.size();
    vector<vector<pair<int, long long>>> cache(n, vector<pair<int, long long>>(n, {-1, -1}));

    for (int s = 0; s < n; s++)
    {
        cache[s][s] = {colors[s], 0};
    }

    for (int s = n - 2; s >= 0; s--)
    {
        for (int e = s + 1; e < n; e++)
        {
            pair<int, long long> minSmk = {0, LLONG_MAX};

            for (int p = s; p < e; p++)
            {
                pair<int, long long> left = cache[s][p];
                pair<int, long long> right = cache[p + 1][e];

                int currComp = (left.first + right.first) % 100;
                long long currSmoke = left.second + right.second + (left.first * right.first);

                if (currSmoke < minSmk.second)
                {
                    minSmk = {currComp, currSmoke};
                }
            }
            cache[s][e] = minSmk;
        }
    }
    return cache[0][n - 1];
}

int main()
{
    vector<int> colors = {40, 60, 20};
    // vector<int> colors = {18, 19};
    int n = colors.size();
    vector<vector<pair<int, long long>>> cache(n, vector<pair<int, long long>>(n, {-1, -1}));
    pair<int, long long> res = minSmokeTD(colors, 0, n - 1, cache);
    cout << "Result : " << res.second << endl;

    pair<int, long long> res2 = minSmokeBU(colors);
    cout << "Result BU : " << res2.second << endl;
}
