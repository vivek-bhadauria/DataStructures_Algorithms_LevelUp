#include <iostream>
#include <queue>
using namespace std;

class MedianHandler
{
    priority_queue<int> leftHeap;                             /* max heap*/
    priority_queue<int, vector<int>, greater<int>> rightHeap; /* min_heap */
public:
    float median;

    void push(int number)
    {
        if (leftHeap.size() == rightHeap.size())
        {
            if (number < median)
            {
                leftHeap.push(number);
                median = leftHeap.top();
            }
            else
            {
                rightHeap.push(number);
                median = rightHeap.top();
            }
        }
        else if (leftHeap.size() > rightHeap.size())
        {
            if (number < median)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(number);
            }
            else
            {
                rightHeap.push(number);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else
        {
            if (number < median)
            {
                leftHeap.push(number);
            }
            else
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(number);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
    }
    
    float getMedian()
    {
        return median;
    }
};

int main()
{
    MedianHandler medianHandler;
    medianHandler.push(10);
    medianHandler.push(15);
    medianHandler.push(5);
    cout << " Current Median 1st call : " << medianHandler.getMedian() << endl;
    medianHandler.push(2);
    medianHandler.push(3);
    cout << " Current Median 2nd call : " << medianHandler.getMedian() << endl;
}