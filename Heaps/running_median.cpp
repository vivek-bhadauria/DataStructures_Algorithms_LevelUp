#include <iostream>
#include <queue>
using namespace std;

int getAbsoluteDiff(int a, int b)
{
    return a > b ? a - b : b - a;
}

vector<float> generateRunningMedian(vector<int> v)
{
    priority_queue<int> leftHeap;/* max heap*/
    priority_queue<int, vector<int>, greater<int>> rightHeap;/* min heap */
    vector<float> res;
    int n, currNum;
    float currMedian = 0;

    for (int i = 0; i < v.size(); i++)
    {
        n = i + 1;
        currNum = v[i];
        if (currNum > currMedian)
        {
            rightHeap.push(currNum);
        }
        else
        {
            leftHeap.push(currNum);
        }

        /* equalize the sizes of two heaps */
        int allowedSizeDiff = n % 2 == 0 ? 0 : 1;
        int currSizeDiff = getAbsoluteDiff(leftHeap.size(), rightHeap.size());
        if (currSizeDiff > allowedSizeDiff)
        {
            /* remove element from maxheap and add to minheap and vice versa */
            if (leftHeap.size() > rightHeap.size())
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
            }
            else
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
            }
        }

        if (n % 2 == 0)
        {
            currMedian = (leftHeap.top() + rightHeap.top()) / 2.0f;
        }
        else
        {
            currMedian = leftHeap.size() > rightHeap.size() ? leftHeap.top() : rightHeap.top();
        }

        res.push_back(currMedian);
    }

    return res;
}

int main()
{

    vector<int> v = {10, 5, 2, 3, 0, 12, 18, 20, 22};

    vector<float> res = generateRunningMedian(v);

    cout << "Medians : ";
    for (auto val : res)
    {
        cout << val << " ";
    }
}