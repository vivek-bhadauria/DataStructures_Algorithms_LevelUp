#include <iostream>
#include <vector>
#include <string>
#include "../../DP_1D/dp_helper.h"

pair<char, int> gameWinner(string str, int s, int e, int n, vector<vector<pair<char, int>>> &cache)
{
    int remaining = e - s + 1;
    int processed = n - remaining;
    char currPlayer = processed % 2 == 0 ? 'O' : 'H';
    char otherPlayer = currPlayer == 'O' ? 'H' : 'O';
    char charToChoose = currPlayer;

    if ((cache[s][e].first == 'O' or cache[s][e].first == 'H') and cache[s][e].second > 0)
    {
        return cache[s][e];
    }

    if (s == e)
    {
        if (str[s] == charToChoose)
        {
            return cache[s][e] = {currPlayer, 1};
        }
        else
        {
            return cache[s][e] = {otherPlayer, 2};
        }
    }

    if (str[s] == charToChoose and str[e] == charToChoose)
    {
        pair<char, int> left = gameWinner(str, s + 1, e, n, cache);
        pair<char, int> right = gameWinner(str, s, e - 1, n, cache);

        if (left.first == right.first)
        {
            if (left.first == currPlayer)
            {
                return cache[s][e] = {currPlayer, max(left.second, right.second)};
            }
            else
            {
                return cache[s][e] = {otherPlayer, min(left.second, right.second)};
            }
        }
        else
        {
            if (left.second > right.second)
            {
                return cache[s][e] = {left.first, left.second};
            }
            else
            {
                return cache[s][e] = {right.first, right.second};
            }
        }
    }
    else if (str[s] == charToChoose)
    {
        return cache[s][e] = gameWinner(str, s + 1, e, n, cache);
    }
    else if (str[e] == charToChoose)
    {
        return cache[s][e] = gameWinner(str, s, e - 1, n, cache);
    }
    else
    {
        return cache[s][e] = {otherPlayer, 1 + (e - s + 1)};
    }
}

int main()
{
    string str = "HOOOOHHO";
    int n = str.length();
    vector<vector<pair<char, int>>> cache(n, vector<pair<char, int>>(n, {'_', 0}));
    pair<char, int> res = gameWinner(str, 0, n - 1, n, cache);
    cout << "Result : {" << res.first << ", " << res.second << "}" << endl;
}