#include <iostream>
#include <vector>
#include <algorithm>
#include "dp_helper.h"
using namespace std;

/* to enforce conditiona that smaller dimension box only can be added */
bool canAdd(vector<int> box1, vector<int> box2)
{
    return box1[0] < box2[0] and box1[1] < box2[1] and box1[2] < box2[2];
}

int maxHeightWithBaseAtTD(vector<vector<int>> boxes, int idx, vector<int> &cache, vector<int> &choice)
{
    if (cache[idx] != 0)
    {
        return cache[idx];
    }

    int maxSubHeight = INT_MIN;
    for (int j = 0; j < idx; j++)
    {
        /* checking each of width, depth, height for index j must be less  width, depth, height for current index idx */
        if (canAdd(boxes[j], boxes[idx]))
        {
            int currIndexMaxHeight = maxHeightWithBaseAtTD(boxes, j, cache, choice);
            if (currIndexMaxHeight > maxSubHeight)
            {
                maxSubHeight = currIndexMaxHeight;
                choice[idx] = j;
            }
        }
    }
    /* if no other box could be added then this box can only achieve height of its own */
    cache[idx] = maxSubHeight == INT_MIN ? boxes[idx][2] : boxes[idx][2] + maxSubHeight;
    choice[idx] = maxSubHeight == INT_MIN ? idx : choice[idx];
    return cache[idx];
}

void printChoices(vector<vector<int>> boxes, vector<int> choice, int maxIdx, int maxHeight)
{
    int i = maxIdx;
    int heightRemaining = maxHeight;
    cout << "Choices" << endl;
    while (heightRemaining > 0)
    {
        cout << boxes[i][0] << " " << boxes[i][1] << " " << boxes[i][2] << endl;
        heightRemaining -= boxes[i][2];
        i = choice[i];
    }
}

bool compareByHeight(vector<int> box1, vector<int> box2)
{
    return box1[2] < box2[2];
}

pair<int, int> findMaxHeightTD(vector<vector<int>> &boxes)
{

    sort(boxes.begin(), boxes.end(), compareByHeight);

    int maxHeight = INT_MIN;
    int maxHeightIdx = -1;
    int n = boxes.size();
    vector<int> cache(n, 0);
    vector<int> choice(n, -1);
    for (int i = 0; i < n; i++)
    {
        int currHeight = maxHeightWithBaseAtTD(boxes, i, cache, choice);
        if (currHeight > maxHeight)
        {
            maxHeight = currHeight;
            maxHeightIdx = i;
        }
    }

    /* display1DCache(cache);
    cout << "Choices ";
    display1DCache(choice); */
    printChoices(boxes, choice, maxHeightIdx, maxHeight);

    return {maxHeight, maxHeightIdx};
}

pair<int, int> findMaxHeightBU(vector<vector<int>> boxes, vector<int> &cache, vector<int> &choice)
{
    sort(boxes.begin(), boxes.end(), compareByHeight);

    cache[0] = boxes[0][2];
    choice[0] = 0;

    /* to track final max height and the index its found at */
    int n = boxes.size();
    int maxHeight = INT_MIN;
    int maxHeightIdx = -1;
    for (int i = 1; i < n; i++)
    {
        int maxSubHeight = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            /* checking each of width, depth, height for index j must be less  width, depth, height for current index i */
            if (canAdd(boxes[j], boxes[i]))
            {
                if (cache[j] > maxSubHeight)
                {
                    maxSubHeight = cache[j];
                    choice[i] = j;
                }
            }
        }
        /* if no other box could be added then this box can only achieve height of its own */
        cache[i] = maxSubHeight == INT_MIN ? boxes[i][2] : boxes[i][2] + maxSubHeight;
        choice[i] = maxSubHeight == INT_MIN ? i : choice[i];

        /* Keep track of the final overall max height and its index */
        if (cache[i] > maxHeight)
        {
            maxHeight = cache[i];
            maxHeightIdx = i;
        }
    }
    return {maxHeight, maxHeightIdx};
}

int main()
{

    vector<vector<int>> boxes = {{2, 1, 2},
                                 {3, 2, 3},
                                 {2, 2, 8},
                                 {2, 3, 4},
                                 {2, 2, 1},
                                 {4, 4, 5}};

    /* Testing top down approach */
    pair<int, int> res = findMaxHeightTD(boxes);
    cout << "Result with top down : " << res.first << " at idx = " << res.second << endl;

    /* Testing bottom up approach */
    int n = boxes.size();
    vector<int> cache(n, 0);
    vector<int> choice(n, -1);
    pair<int, int> res2 = findMaxHeightBU(boxes, cache, choice);
    cout << "Result with bottom up : " << res2.first << " at idx = " << res2.second << endl;
    /* display1DCache(cache);
    cout << "Choices ";
    display1DCache(choice); */
    printChoices(boxes, choice, res2.second, res2.first);
}