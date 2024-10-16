#include "graph.h"

vector<vector<int>> findShortestDistance(Graph g, int u)
{
    vector<bool> visited(g.v, false);
    vector<int> dist(g.v, 0);
    vector<int> parent(g.v, -1);
    vector<vector<int>> res;
    queue<int> q;

    q.push(u);
    visited[u] = true;
    dist[u] = 0;
    parent[u] = u;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto adj : g.l[curr])
        {
            if (!visited[adj])
            {
                q.push(adj);
                visited[adj] = true;
                dist[adj] = dist[curr] + 1;
                parent[adj] = curr;
            }
        }
    }

    res.push_back(dist);
    res.push_back(parent);
    return res;
}

void printShortestPath(int u, int v, vector<int> parent)
{
    string path = "";
    int curr = v;

    while (curr != u)
    {
        path = " -> " + to_string(curr) + path;
        curr = parent[curr];
    }
    path = to_string(curr) + path;
    cout << path << endl;
}

void printShortestPathRecursive(int u, int v, vector<int> parent)
{
    if (u == v)
    {
        cout << u;
        return;
    }
    printShortestPathRecursive(u, parent[v], parent);
    cout << " --> " << v;
}

int main()
{

    Graph g(7);

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.print();

    int u;
    cin >> u;
    vector<vector<int>> res = findShortestDistance(g, u);
    vector<int> dist = res[0];
    vector<int> parent = res[1];

    cout << "Shortest Distance of each node from node : " << u << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " --> " << dist[i] << endl;
    }

    cout << "Shortest Paths from node " << u << " to all other nodes" << endl;
    for (int i = 0; i < g.v; i++)
    {
        cout << "Path to " << i << " : ";
        printShortestPath(u, i, parent);
    }

    cout << "Shortest Paths from node " << u << " to all other nodes - Recursive" << endl;
    for (int i = 0; i < g.v; i++)
    {
        cout << "Path to " << i << " : ";
        printShortestPathRecursive(u, i, parent);
        cout << endl;
    }
}