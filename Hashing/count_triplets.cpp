#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long countTripletsInGP(vector<int> v, int r)
{

    unordered_map<long, long> left, right;
    int n = v.size();
    long count = 0;

    /* prepare a map of each element to its index*/
    for (int i = 0; i < n; i++)
    {
        right[v[i]]++;
        left[v[i]] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        int curr = v[j];

        right[curr]--; /* as current won't be part of right map anymore */

        if (curr % r == 0)
        {
            count += left[curr / r] * right[curr * r];
        }

        left[curr]++; /* as current is done so it will be a part of left map */
    }
    return count;
}

int main()
{

    vector<int> v = {1, 16, 4, 16, 64, 16};
    int ratio;
    cin >> ratio;
    long res = countTripletsInGP(v, ratio);
    cout << "Count of triplets in GP with ratio = " << ratio << " : " << res;
}
