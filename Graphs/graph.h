#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    void dfsHelper(int u, vector<bool> &visited)
    {
        visited[u] = true;

        /* process node */
        cout << u << " -> ";

        for (auto adj : l[u])
        {
            if (!visited[adj])
            {
                dfsHelper(adj, visited);
            }
        }
    }

public:
    int v;
    list<int> *l;
    bool directed;

    Graph(int v, bool directed = false)
    {
        this->v = v;
        this->directed = directed;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);

        if (!directed)
        {
            l[v].push_back(u);
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " --> ";
            for (auto node : l[i])
            {
                cout << node << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void dfs(int u)
    {
        vector<bool> visited(v, false);
        cout << "DFS : ";
        dfsHelper(u, visited);
        cout << endl;
    }

    void bfs(int u)
    {
        vector<bool> visited(v, false);
        queue<int> q;

        visited[u] = true;
        q.push(u);

        cout << "BFS : ";
        while (!q.empty())
        {

            int curr = q.front();
            q.pop();

            /* process node */
            cout << curr << " -> ";

            for (auto adj : l[curr])
            {
                if (!visited[adj])
                {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }
        cout << endl;
    }

    void dfsIterative(int u){
        vector<bool> visited(v,false);
        stack<int> stk;

        visited[u] = true;
        stk.push(u);
        
        cout<<"DFS iterative : ";
        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();

            /* process node */
            cout<<curr<<" -> ";

            for(auto adj : l[curr]){
                if(!visited[adj]){
                    visited[adj] = true;
                    stk.push(adj);
                }
            }
        }
        cout<<endl;
    }
};

class Node
{
public:
    string name;
    list<string> adj;

    Node(string name)
    {
        this->name = name;
    }
};

class GraphN
{
    void dfsHelper(string name, unordered_map<string, bool> &visited)
    {
        visited[name] = true;

        /* process node */
        cout << name << " -> ";

        for (auto adjName : nodeMap[name]->adj)
        {
            if (!visited[adjName])
            {
                dfsHelper(adjName, visited);
            }
        }
    }

public:
    vector<string> nodeNames;
    unordered_map<string, Node *> nodeMap;
    bool directed;

    GraphN(vector<string> names, bool directed = false)
    {
        nodeNames = names;
        this->directed = directed;
        for (auto name : names)
        {
            nodeMap[name] = new Node(name);
        }
    }

    void addEdge(string u, string v)
    {
        nodeMap[u]->adj.push_back(v);

        if (!directed)
        {
            nodeMap[v]->adj.push_back(u);
        }
    }

    void print()
    {
        for (auto pr : nodeMap)
        {
            string name = pr.first;
            Node *node = pr.second;
            cout << name << " --> ";
            for (auto adjStr : node->adj)
            {
                cout << adjStr << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void dfs(string name)
    {
        unordered_map<string, bool> visited;
        cout << "DFS : ";
        dfsHelper(name, visited);
        cout << endl;
    }

    void bfs(string name)
    {
        unordered_map<string, bool> visited;
        queue<string> q;

        visited[name] = true;
        q.push(name);

        cout << "BFS : ";
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            /* process node */
            cout << curr << " -> ";

            for (auto adjName : nodeMap[curr]->adj)
            {
                if (!visited[adjName])
                {
                    visited[adjName] = true;
                    q.push(adjName);
                }
            }
        }
        cout << endl;
    }
};

class GraphM
{
    void dfsHelper(int u, vector<bool> &visited)
    {
        visited[u] = true;

        /* process node */
        cout << u << " -> ";

        for (int i = 0; i < v; i++)
        {
            if (mat[u][i] == 1 and !visited[i])
            {
                dfsHelper(i, visited);
            }
        }
    }

public:
    int v;
    vector<vector<int>> mat;
    bool directed;

    GraphM(int v, bool directed = false)
    {
        this->v = v;
        this->directed = directed;
        vector<vector<int>> temp(v, vector<int>(v, 0));
        mat = temp;
    }

    void addEdge(int u, int v)
    {
        mat[u][v] = 1;
        if (!directed)
        {
            mat[v][u] = 1;
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " --> ";
            for (auto node : mat[i])
            {
                cout << node << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void dfs(int u)
    {
        vector<bool> visited(v, false);
        cout << "DFS : ";
        dfsHelper(u, visited);
        cout << endl;
    }

    void bfs(int u)
    {
        vector<bool> visited(v, false);
        queue<int> q;

        visited[u] = true;
        q.push(u);

        cout << "BFS : ";
        while (!q.empty())
        {

            int curr = q.front();
            q.pop();

            /* process node */
            cout << curr << " -> ";

            for (int i = 0; i < v; i++)
            {
                if (mat[curr][i] == 1 and !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};
