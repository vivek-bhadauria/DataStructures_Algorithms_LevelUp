#include <iostream>
#include <vector>
#include <string>
using namespace std;

int isMatchNaive(string s, string ptrn, int i, int j, int slen, int plen, vector<vector<int>> &cache)
{
    if (i == slen and j == plen)
    {
        return cache[i][j] = 1;
    }
    if (j == plen)
    {
        return cache[i][j] = 0;
    }
    if (i == slen)
    {
        while (j < plen)
        {
            if (ptrn[j] != '*')
            {
                return false;
            }
            j++;
        }
        return true;
    }
    if (cache[i][j] != -1)
    {
        return cache[i][j];
    }
    if (ptrn[j] == '*')
    {
        /* matches 0 or more */
        bool matchesZero = isMatchNaive(s, ptrn, i, j + 1, slen, plen, cache);
        if (matchesZero)
        {
            return cache[i][j] = 1;
        }
        for (int k = 1; (i + k) < slen; k++)
        {
            bool matchesOneOrMore = isMatchNaive(s, ptrn, i + k, j + 1, slen, plen, cache);
            if (matchesOneOrMore)
            {
                return cache[i][j] = 1;
            }
        }
    }
    else if (ptrn[j] == '?' or ptrn[j] == s[i])
    {
        /* matches 1 */
        return cache[i][j] = isMatchNaive(s, ptrn, i + 1, j + 1, slen, plen, cache);
    }
    return cache[i][j] = 0;
}

int isMatchOptimizedTD(string s, string ptrn, int i, int j, int slen, int plen, vector<vector<int>> &cache)
{
    if (i == slen and j == plen)
    {
        return cache[i][j] = 1;
    }
    if (j == plen)
    {
        return cache[i][j] = 0;
    }
    if (i == slen)
    {
        while (j < plen)
        {
            if (ptrn[j] != '*')
            {
                return 0;
            }
            j++;
        }
        return 1;
    }
    if (cache[i][j] != -1)
    {
        return cache[i][j];
    }
    if (ptrn[j] == '*')
    {
        /* matches 0 or more */
        bool matchesZero = isMatchOptimizedTD(s, ptrn, i, j + 1, slen, plen, cache);
        bool matchesOneOrMore = isMatchOptimizedTD(s, ptrn, i + 1, j, slen, plen, cache);
        return cache[i][j] = matchesZero or matchesOneOrMore;
    }
    else if (ptrn[j] == '?' or ptrn[j] == s[i])
    {
        /* matches 1 */
        return cache[i][j] = isMatchOptimizedTD(s, ptrn, i + 1, j + 1, slen, plen, cache);
    }
    return cache[i][j] = 0;
}

int isMatchOptimizedBU(string s, string ptrn)
{
    int slen = s.length();
    int plen = ptrn.length();
    vector<vector<int>> cache(slen + 1, vector<int>(plen + 1, 0));
    cache[slen][plen] = 1;

    for (int i = 0; i < plen; i++)
    {
        int j = i;
        while (j < plen)
        {
            if (ptrn[j] != '*')
            {
                break;
            }
            j++;
        }
        if (j == plen)
        {
            cache[slen][i] = 1;
        }
        else
        {
            cache[slen][i] = 0;
        }
    }

    for (int i = slen - 1; i >= 0; i--)
    {
        for (int j = plen - 1; j >= 0; j--)
        {
            if (ptrn[j] == '*')
            {
                cache[i][j] = cache[i][j + 1] + cache[i + 1][j];
            }
            else if (ptrn[j] == '?' or ptrn[j] == s[i])
            {
                cache[i][j] = cache[i + 1][j + 1];
            }
            else
            {
                cache[i][j] = 0;
            }
        }
    }
    return cache[0][0];
}

int main()
{
    string s = "aabab";
    string ptrn = "*ab**";
    int slen = s.length();
    int plen = ptrn.length();
    vector<vector<int>> cache(slen + 1, vector<int>(plen + 1, -1));
    int matches = isMatchOptimizedTD(s, ptrn, 0, 0, slen, plen, cache);
    string matchRes = matches ? "true" : "false";
    cout << "Pattern matches ? " << matchRes << endl;

    int matches2 = isMatchOptimizedBU(s, ptrn);
    string matchRes2 = matches2 ? "true" : "false";
    cout << "Pattern matches BU ? " << matchRes2 << endl;
}