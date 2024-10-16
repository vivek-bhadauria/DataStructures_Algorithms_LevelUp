#include <iostream>
#include <vector>
using namespace std;

int minJumpsRecursive(vector<int> v, int i, int n, vector<int> &cache, vector<int> &choice)
{
    if (i == n - 1)
    {
        cache[i] = 0;
        return 0;
    }
    if (cache[i] != INT_MAX)
    {
        return cache[i];
    }

    int res = INT_MAX;
    for (int j = 1; j <= v[i] and i + j < n; j++)
    {
        int curr = minJumpsRecursive(v, i + j, n, cache, choice);
        if (curr < res)
        {
            res = curr;
            choice[i] = j;
        }
    }
    cache[i] = 1 + res;
    return cache[i];
}

int minJumpsIterative(vector<int> v, int idx, int n, vector<int> &cache, vector<int> &choice)
{
    cache[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= v[i] and i + j < n; j++)
        {
            if (cache[i + j] < cache[i])
            {
                cache[i] = cache[i + j];
                choice[i] = j;
            }
        }
        cache[i] = 1 + cache[i];
    }
    return cache[idx];
}

void printPathTaken(vector<int> v, vector<int> choice, int n)
{

    int i = 0;
    cout << "Path : ";
    while (i != n - 1)
    {
        cout << v[i] << " --> ";
        i = i + choice[i];
    }
    cout << v[n - 1];
    cout << endl;
}

int main()
{

    vector<int> v = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
    int n = v.size();
    vector<int> cache(n, INT_MAX);
    vector<int> cache1(n, INT_MAX);
    vector<int> choice(n, 0);
    vector<int> choice1(n, 0);
    int res = minJumpsRecursive(v, 0, n, cache, choice);
    cout << "Result : " << res << endl;
    printPathTaken(v, choice, n);
    int res2 = minJumpsIterative(v, 0, n, cache1, choice1);
    cout << "Result2 : " << res2 << endl;
    printPathTaken(v, choice1, n);
}