#include <iostream>
#include <vector>
#include <string>
#include "../DP_1D/dp_helper.h"
using namespace std;

int countSubSeqTD(string s1, string s2, int i, int j, vector<vector<int>> &cache)
{
    if (i == s1.length())
    {
        cache[i][j] = 0;
        return cache[i][j];
    }
    if (j == s2.length())
    {
        cache[i][j] = 1;
        return cache[i][j];
    }
    if (cache[i][j] != -1)
    {
        return cache[i][j];
    }
    if (s1[i] == s2[j])
    {
        int inc = countSubSeqTD(s1, s2, i + 1, j + 1, cache);
        int exc = countSubSeqTD(s1, s2, i + 1, j, cache);
        cache[i][j] = inc + exc;
        return cache[i][j];
    }
    else
    {
        cache[i][j] = countSubSeqTD(s1, s2, i + 1, j, cache);
        return cache[i][j];
    }
}

int countSubSeqBU(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> cache(n1 + 1, vector<int>(n2 + 1, -1));

    /* init base cases */
    for (int i = 0; i <= n2; i++)
    {
        cache[n1][i] = 0;
    }

    for (int i = 0; i <= n1; i++)
    {
        cache[i][n2] = 1;
    }

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                cache[i][j] = cache[i + 1][j + 1] + cache[i + 1][j];
            }
            else
            {
                cache[i][j] = cache[i + 1][j];
            }
        }
    }
    return cache[0][0];
}

int main()
{

    string s1 = "ABCDCE";
    string s2 = "ABC";
    int n1 = s1.length();
    int n2 = s2.length();

    /* Testing Top Down Approach */
    vector<vector<int>> cache(n1 + 1, vector<int>(n2 + 1, -1));
    int res = countSubSeqTD(s1, s2, 0, 0, cache);
    cout << "Result : " << res << endl;

    /* Testing Bottom Up Approach */
    int res2 = countSubSeqBU(s1, s2);
    cout << "Result2 : " << res2 << endl;
}