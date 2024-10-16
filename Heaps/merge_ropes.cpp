#include <iostream>
#include <queue>
using namespace std;

int minCostMergeRopes(vector<int> v)
{

    priority_queue<int, vector<int>, greater<int>> heap; /* min heap */
    int cost = 0;
    for (auto val : v)
    {
        heap.push(val);
    }

    while (!heap.empty())
    {
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        heap.pop();
        int currSum = first + second;
        cost += currSum;
        if (!heap.empty())
        {
            heap.push(currSum);
        }
    }
    return cost;
}

int main()
{
    vector<int> v = {4, 3, 2, 6};
    int ans = minCostMergeRopes(v);
    cout << "Minimum cost of merging ropes : " << ans;
}