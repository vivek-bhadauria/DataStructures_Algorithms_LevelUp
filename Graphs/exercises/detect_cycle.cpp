#include "../graph.h"

bool hasCycleBFS(Graph g, int u)
{
    vector<bool> visited(g.v, false);
    vector<int> parent(g.v, -1); /* Not required for directed graph */
    queue<int> q;

    q.push(u);
    visited[u] = true;
    parent[u] = -1;

    while (!q.empty())
    {

        int curr = q.front();
        q.pop();

        for (auto adj : g.l[curr])
        {
            if (visited[adj])
            {
                if (!g.directed and parent[curr] != adj)
                {
                    return true;
                }
                else if (g.directed)
                {
                    // curr -> adj edge must be backedge for cycle to be present
                    int curr1 = curr;
                    int prnt = parent[curr1];
                    while (prnt != -1 and adj != prnt)
                    {
                        prnt = parent[curr1];
                        curr1 = prnt;
                    }
                    if (adj == prnt)
                    {
                        return true;
                    }
                }
            }
            else
            {
                q.push(adj);
                visited[adj] = true;
                parent[adj] = curr;
            }
        }
    }

    return false;
}

bool hasCycleDFSHelper(Graph g, int u, vector<bool> &visited, vector<bool> &stacked, vector<int> &parent)
{

    visited[u] = true;
    stacked[u] = true;

    for (auto adj : g.l[u])
    {
        if (visited[adj])
        {
            if (!g.directed and parent[u] != adj and stacked[adj])
            {
                return true;
            }
            else if (g.directed and stacked[adj])
            {
                return true;
            }
        }
        else
        {
            parent[adj] = u;
            bool cycleFound = hasCycleDFSHelper(g, adj, visited, stacked, parent);
            if (cycleFound)
            {
                return true;
            }
        }
    }

    stacked[u] = false;
    return false;
}

bool hasCycleDFS(Graph g, int u)
{
    vector<bool> visited(g.v, false);
    vector<bool> stacked(g.v, false); /* tracks nodes which are on stack */
    vector<int> parent(g.v, -1);      /* Not required for directed graph */

    return hasCycleDFSHelper(g, u, visited, stacked, parent);
}

int main()
{

    cout << "========= TESTING UNDIRECTED GRAPHS =========" << endl;
    Graph g1(6);

    g1.addEdge(0, 1);
    g1.addEdge(0, 4);
    g1.addEdge(0, 5);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);

    cout << "Graph - 1" << endl;
    g1.print();

    Graph g2(6);

    g2.addEdge(0, 1);
    g2.addEdge(0, 4);
    g2.addEdge(0, 5);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(4, 5);

    cout << "Graph - 2" << endl;
    g2.print();

    string ans1 = hasCycleBFS(g1, 0) ? "YES" : "NO";
    cout << "BFS -> Graph - 1 has cycle ? " << ans1 << endl;

    string ans2 = hasCycleBFS(g2, 0) ? "YES" : "NO";
    cout << "BFS -> Graph - 2 has cycle ? " << ans2 << endl;

    string ans3 = hasCycleDFS(g1, 0) ? "YES" : "NO";
    cout << "DFS -> Graph - 1 has cycle ? " << ans3 << endl;

    string ans4 = hasCycleDFS(g2, 0) ? "YES" : "NO";
    cout << "DFS -> Graph - 2 has cycle ? " << ans4 << endl;

    cout << "========= TESTING DIRECTED GRAPHS =========" << endl;
    Graph g3(6, true);

    g3.addEdge(0, 1);
    g3.addEdge(0, 4);
    g3.addEdge(0, 5);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(5, 4);

    cout << "Graph - 3" << endl;
    g3.print();

    Graph g4(6, true);

    g4.addEdge(0, 1);
    g4.addEdge(0, 5);
    g4.addEdge(1, 2);
    g4.addEdge(2, 3);
    g4.addEdge(4, 0);
    g4.addEdge(5, 4);

    cout << "Graph - 4" << endl;
    g4.print();

    string ans5 = hasCycleBFS(g3, 0) ? "YES" : "NO";
    cout << "BFS -> Graph - 3 has cycle ? " << ans5 << endl;

    string ans6 = hasCycleBFS(g4, 0) ? "YES" : "NO";
    cout << "BFS -> Graph - 4 has cycle ? " << ans6 << endl;

    string ans7 = hasCycleDFS(g3, 0) ? "YES" : "NO";
    cout << "DFS -> Graph - 3 has cycle ? " << ans7 << endl;

    string ans8 = hasCycleDFS(g4, 0) ? "YES" : "NO";
    cout << "DFS -> Graph - 4 has cycle ? " << ans8 << endl;
}