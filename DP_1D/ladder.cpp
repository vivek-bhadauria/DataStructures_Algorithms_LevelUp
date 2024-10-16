#include <iostream>
#include <vector>
#include "dp_helper.h"
using namespace std;

int countWaysToClimbLadder(int n, int k)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        cnt += countWaysToClimbLadder(n - i, k);
    }
    return cnt;
}

int countWaysToClimbLadderDP(int n, int k, vector<int> &cache)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        cache[n] = 1;
        return cache[n];
    }
    if (cache[n] != -1)
    {
        return cache[n];
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        cnt += countWaysToClimbLadderDP(n - i, k, cache);
    }
    cache[n] = cnt;
    return cache[n];
}

int countWaysToClimbLadderDPTD(int n, int k)
{
    vector<int> cache(n + 1, -1);
    int cnt = countWaysToClimbLadderDP(n, k, cache);
    return cnt;
}

/* Space Complexity : O(K)
   Time Complexity : K + (N-K) * K = K *(N-K+1)
   Used Pre computed sum approach with shifting required in K size array
*/
int countWaysToClimbLadderBU(int n, int k)
{
    vector<int> cache(k + 1, -1);
    cache[0] = 1;
    int sum = cache[0];

    /* until k, cache[i] is sum upto i-1 */
    for (int i = 1; i <= k; i++)
    {
        cache[i] = sum;
        sum += cache[i];
    }

    for (int i = k + 1; i <= n; i++)
    {
        sum -= cache[0];

        for (int j = 0; j < k; j++)
        {
            cache[j] = cache[j + 1];
        }
        cache[k] = sum;

        sum += cache[k];
    }
    return cache[k];
}

/* Space Complexity : O(N)
   Time Complexity : O(N)
   Used Pre computed sum approach i.e. arr[n-1]+...+arr[n-k] = arr[n] - arr[n-k-1];
*/
int countWaysToClimbLadderBU2(int n, int k)
{
    vector<int> cache(n + 1, -1);
    cache[0] = 1;
    int sum = cache[0];

    /* until k, cache[i] is sum upto i-1 */
    for (int i = 1; i <= k; i++)
    {
        cache[i] = sum;
        sum += cache[i];
    }

    for (int i = k + 1; i <= n; i++)
    {
        sum -= cache[i - k - 1];

        cache[i] = sum;
        sum += cache[i];
    }
    return cache[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int res = countWaysToClimbLadder(n, k);
    cout << "Result : " << res << endl;
    int res2 = countWaysToClimbLadderDPTD(n, k);
    cout << "Result2 : " << res2 << endl;
    int res3 = countWaysToClimbLadderBU(n, k);
    cout << "Result3 : " << res3 << endl;
    int res4 = countWaysToClimbLadderBU2(n, k);
    cout << "Result4 : " << res4 << endl;
}