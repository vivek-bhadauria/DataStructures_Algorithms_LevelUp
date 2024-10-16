#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void printPath(int s, int e, vector<int> parent)
{
    if (s == e)
    {
        cout << s;
        return;
    }

    printPath(s, parent[e], parent);
    cout << " --> " << e;
}

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    vector<int> snks(n + 1, 0);
    vector<int> ldrs(n + 1, 0);
    vector<int> diceCount(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, 0);
    queue<int> q;

    /* preparing map of snakes and ladders */
    for (auto pr : snakes)
    {
        snks[pr.first] = pr.second;
    }

    for (auto pr : ladders)
    {
        ldrs[pr.first] = pr.second;
    }

    /* applying BFS to track shortest path and shortest distance from source to target */
    q.push(1);
    visited[1] = true;
    diceCount[1] = 0;
    parent[1] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nxt = curr + i;
            if (nxt <= n and snks[nxt] != 0)
            {
                nxt = snks[nxt];
            }
            else if (nxt <= n and ldrs[nxt] != 0)
            {
                nxt = ldrs[nxt];
            }

            if (!visited[nxt] and nxt <= n)
            {
                q.push(nxt);
                visited[nxt] = true;
                diceCount[nxt] = diceCount[curr] + 1;
                parent[nxt] = curr;
                if (nxt == n)
                {
                    cout << "Shortest Path : ";
                    printPath(1, n, parent);
                    cout << endl;
                    return diceCount[n];
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n = 36;
    vector<pair<int, int>> snakes = {
        {17, 4},
        {20, 6},
        {34, 12},
        {24, 16},
        {32, 30}};

    vector<pair<int, int>> ladders = {
        {2, 15},
        {5, 7},
        {9, 27},
        {18, 29},
        {25, 35}};

    int res = min_dice_throws(n, snakes, ladders);
    cout << "Result = " << res;
}