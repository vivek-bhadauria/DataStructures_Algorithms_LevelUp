#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isPalindrome(string str, int s, int e)
{
    while (s < e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int minPartitionTD(string str, int s, int e, vector<vector<int>> &cache)
{
    if (s == e or isPalindrome(str, s, e))
    {
        return cache[s][e] = 0;
    }
    if (cache[s][e] != -1)
    {
        return cache[s][e];
    }
    int minPart = INT_MAX;
    for (int k = s; k < e; k++)
    {
        int left = minPartitionTD(str, s, k, cache);
        int right = minPartitionTD(str, k + 1, e, cache);
        int currPart = left + right + 1;
        minPart = min(minPart, currPart);
    }
    return cache[s][e] = minPart;
}

int minPartitionBU(string str)
{

    int n = str.length();
    vector<vector<int>> cache(n, vector<int>(n, 0));

    for (int s = 0; s < n; s++)
    {
        cache[s][s] = 0;
    }

    for (int s = n - 2; s >= 0; s--)
    {
        for (int e = s + 1; e < n; e++)
        {
            if (isPalindrome(str, s, e))
            {
                cache[s][e] = 0;
            }
            else
            {
                int minPart = INT_MAX;
                for (int k = s; k < e; k++)
                {
                    int left = cache[s][k];
                    int right = cache[k + 1][e];
                    int currPart = left + right + 1;
                    minPart = min(minPart, currPart);
                }
                cache[s][e] = minPart;
            }
        }
    }
    return cache[0][n - 1];
}

int main()
{
    string s = "abcde";
    int n = s.length();
    vector<vector<int>> cache(n, vector<int>(n, -1));
    int minPart = minPartitionTD(s, 0, n - 1, cache);
    cout << "Minimum Partition TD : " << minPart << endl;

    int minPart2 = minPartitionBU(s);
    cout << "Minimum Partition BU : " << minPart2 << endl;
}