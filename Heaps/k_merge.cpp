#include <iostream>
#include <queue>
using namespace std;

class Pair
{
public:
    int val;
    int idx;

    Pair(int val, int idx)
    {
        this->val = val;
        this->idx = idx;
    }
};

class PairCompare
{
public:
    bool operator()(Pair a, Pair b)
    {
        return a.val > b.val;
    }
};

vector<int> kMerge(vector<vector<int>> v, int k)
{
    vector<int> currIdxs(k, -1);
    priority_queue<Pair, vector<Pair>, PairCompare> heap; /* min heap */
    vector<int> res;

    /* add elements at first index of each array */
    for (int i = 0; i < k; i++)
    {
        Pair p(v[i][0], i);
        currIdxs[i]++;
        heap.push(p);
    }

    while (!heap.empty())
    {
        Pair top = heap.top();
        heap.pop();

        res.push_back(top.val);

        /* move the index ahead for vector from which current top comes */
        currIdxs[top.idx]++;

        /* push the elment from the next index of same vector from which popped item comes
          v[top.idx] -> vector from which popped element comes
          currIdxs[top.idx] -> current element index within vector from which popped element comes
        */
        int i = top.idx;
        int j = currIdxs[top.idx];

        if (j < v[i].size())
        {
            Pair p(v[i][j], i);
            heap.push(p);
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> v = {{1, 3, 15},
                             {2, 4, 6},
                             {0, 9, 10, 11}};

    int k = v.size();
    vector<int> res = kMerge(v, k);

    for (auto val : res)
    {
        cout << val << " ";
    }
}