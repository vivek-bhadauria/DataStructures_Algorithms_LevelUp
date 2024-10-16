#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> &g, int i, vector<bool> &visited)
{
    int c = 0;
    queue<int> q;

    q.push(i);
    visited[i] = true;
    c++;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto adj : g[curr])
        {
            if (!visited[adj])
            {
                q.push(adj);
                visited[adj] = true;
                c++;
            }
        }
    }
    return c;
}

int count_pairs(int N, vector<pair<int, int>> astronauts)
{
    vector<vector<int>> g(N);
    vector<bool> visited(N, false);
    int rem = N;
    int ans = 0;

    /* prepare graph */
    for (auto p : astronauts)
    {
        int u = p.first;
        int v = p.second;
        g[u].push_back(v);
    }

    for (int i = 0; i < N and rem > 0; i++)
    {
        if (!visited[i])
        {
            /* find size of astronauts in a country i.e. size of each connected component */
            int cs = bfs(g, i, visited);
            rem = rem - cs;
            ans = ans + cs * rem;
        }
    }
    return ans;
}

int main()
{
    int N = 6;
    vector<pair<int, int>> astronauts = {{1, 2}, {3, 4}, {4, 5}};

    int res = count_pairs(N, astronauts);
    cout << "Res : " << res;
}