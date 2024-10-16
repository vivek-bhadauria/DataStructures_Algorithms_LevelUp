#include "graph.h"

int main()
{

    GraphM g1(6);

    g1.addEdge(0, 1);
    g1.addEdge(0, 4);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(3, 5);
    g1.addEdge(4, 5);

    cout << "====== Graph Matrix Form ======" << endl;
    g1.print();
    g1.dfs(0);
    g1.bfs(0);

    Graph g2(6);

    g2.addEdge(0, 1);
    g2.addEdge(0, 4);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.addEdge(3, 5);
    g2.addEdge(4, 5);

    cout << "====== Graph List Form ======" << endl;
    g2.print();
    g2.dfs(0);
    g2.bfs(0);
    g2.dfsIterative(0);

    vector<string> cities = {"New York", "London", "Paris", "Delhi"};
    GraphN g3(cities, true);

    g3.addEdge("New York", "London");
    g3.addEdge("Paris", "New York");
    g3.addEdge("Delhi", "London");
    g3.addEdge("Delhi", "Paris");

    cout << "====== Graph Node Form ======" << endl;
    g3.print();
    g3.dfs("Delhi");
    g3.bfs("Delhi");

    Graph g4(7);

    g4.addEdge(1, 0);
    g4.addEdge(1, 2);
    g4.addEdge(0, 4);
    g4.addEdge(2, 3);
    g4.addEdge(3, 4);
    g4.addEdge(3, 5);
    g4.addEdge(4, 5);
    g4.addEdge(5, 6);

    cout << "====== Graph-2 List Form ======" << endl;
    g4.print();
    g4.dfs(1);
    g4.bfs(1);
    g4.dfsIterative(1);
}