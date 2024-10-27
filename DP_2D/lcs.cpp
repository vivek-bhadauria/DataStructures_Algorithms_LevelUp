#include <iostream>
#include <vector>
#include <string>
#include "../DP_1D/dp_helper.h"
using namespace std;

int lcsTD(string str1, string str2, int i, int j, int m, int n, vector<vector<int>> &cache)
{
    if (i == m or j == n)
    {
        cache[i][j] = 0;
        return cache[i][j];
    }
    if (cache[i][j] != 0)
    {
        return cache[i][j];
    }
    if (str1[i] == str2[j])
    {
        cache[i][j] = 1 + lcsTD(str1, str2, i + 1, j + 1, m, n, cache);
    }
    else
    {
        cache[i][j] = max(lcsTD(str1, str2, i + 1, j, m, n, cache), lcsTD(str1, str2, i, j + 1, m, n, cache));
    }
    return cache[i][j];
}

int lcsBU(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (str1[i] == str2[j])
            {
                cache[i][j] = 1 + cache[i + 1][j + 1];
            }
            else
            {
                cache[i][j] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
    }
    return cache[0][0];
}

void printSolution(string str1, string str2, vector<vector<int>> &cache)
{

    int i = 0;
    int j = 0;
    string res = "";
    while (i < str1.length() and j < str2.length())
    {
        if (str1[i] == str2[j])
        {
            res.push_back(str1[i]);
            i++;
            j++;
        }
        else
        {
            if (cache[i + 1][j] > cache[i][j + 1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    cout << "Solution : " << res << endl;
}

int main()
{
    string str1 = "ABCD";
    string str2 = "ABEDG";
    int m = str1.length();
    int n = str2.length();

    /* Testing Top Down Approach */
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));
    int res = lcsTD(str1, str2, 0, 0, m, n, cache);
    cout << "Result = " << res << endl;
    printSolution(str1, str2, cache);

    /* Testing Bottom Up Approach */
    int res2 = lcsBU(str1, str2);
    cout << "Result2 = " << res2 << endl;
}
