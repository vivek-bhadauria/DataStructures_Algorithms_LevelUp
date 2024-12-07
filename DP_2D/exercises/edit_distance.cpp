#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findEditDistanceTD(string s1, string s2, int i, int j, int len1, int len2, vector<vector<int>> &cache)
{
    if (i == len1 and j == len2)
    {
        return cache[i][j] = 0;
    }
    if (i == len1 and j < len2)
    {
        return cache[i][j] = len2 - j + 1;
    }
    if (i < len1 and j == len2)
    {
        return cache[i][j] = len1 - i + 1;
    }

    if (cache[i][j] != -1)
    {
        return cache[i][j];
    }

    if (s1[i] == s2[j])
    {

        return cache[i][j] = findEditDistanceTD(s1, s2, i + 1, j + 1, len1, len2, cache);
    }
    else if (len1 - i < len2 - j)
    {
        /* insert to s1 or replace */
        return cache[i][j] = 1 + min(findEditDistanceTD(s1, s2, i, j + 1, len1, len2, cache),
                                     findEditDistanceTD(s1, s2, i + 1, j + 1, len1, len2, cache));
    }
    else if (len1 - i > len2 - j)
    {
        /* delete from s1 or replace */
        return cache[i][j] = 1 + min(findEditDistanceTD(s1, s2, i + 1, j, len1, len2, cache),
                                     findEditDistanceTD(s1, s2, i + 1, j + 1, len1, len2, cache));
    }
    else
    {
        /* replace */
        return cache[i][j] = 1 + findEditDistanceTD(s1, s2, i + 1, j + 1, len1, len2, cache);
    }
}

int findEditDistanceBU(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> cache(len1 + 1, vector<int>(len2 + 1, -1));

    for (int j = 0; j < len2; j++)
    {
        cache[len1][j] = len2 - j + 1;
    }

    for (int i = 0; i < len1; i++)
    {
        cache[i][len2] = len1 - i + 1;
    }

    cache[len1][len2] = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {

                cache[i][j] = cache[i + 1][j + 1];
            }
            else if (len1 - i < len2 - j)
            {
                /* insert to s1 or replace */
                cache[i][j] = 1 + min(cache[i][j + 1], cache[i + 1][j + 1]);
            }
            else if (len1 - i > len2 - j)
            {
                /* delete from s1 or replace */
                cache[i][j] = 1 + min(cache[i + 1][j], cache[i + 1][j + 1]);
            }
            else
            {
                /* replace */
                cache[i][j] = 1 + cache[i + 1][j + 1];
            }
        }
    }

    return cache[0][0];
}

int main()
{

    string s1 = "food";
    string s2 = "money";
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> cache(len1 + 1, vector<int>(len2 + 1, -1));
    int dist = findEditDistanceTD(s1, s2, 0, 0, len1, len2, cache);
    cout << "Edit Distance : " << dist << endl;

    int dist2 = findEditDistanceBU(s1, s2);
    cout << "Edit Distance BU : " << dist2 << endl;
}