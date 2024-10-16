#include "weighted_graph.h"
#include <set>
#include <vector>
using namespace std;

vector<int> dijkstraAlgo(WeightedGraph g, int u)
{
    vector<int> dist(g.v, INT_MAX);
    set<pair<int, int>> set; /* first -> distance, second -> node; ordered on distance */

    dist[u] = 0;
    set.insert({dist[u], u});

    while (!set.empty())
    {
        auto curr = set.begin();
        int currDist = curr->first;
        int currNode = curr->second;
        set.erase(curr);

        for (auto p : g.l[currNode])
        {
            int adjNode = p.first;
            int adjDist = p.second;
            int newDist = currDist + adjDist;
            if (dist[adjNode] > newDist)
            {
                /* insert or update the set for adj node */
                auto found = set.find({dist[adjNode], adjNode});
                if (found != set.end())
                {
                    set.erase(found);
                }
                dist[adjNode] = newDist;
                set.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{

    WeightedGraph g(5);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 3);

    g.print();

    int u;
    cin >> u;
    vector<int> dist = dijkstraAlgo(g, u);
    for (int i = 0; i < g.v; i++)
    {
        cout << "Shortest distance of node " << i << " from node " << u << " : " << dist[i] << endl;
    }
}