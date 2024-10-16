#include<iostream>
#include<list>

using namespace std;

class WeightedGraph{
    public:
        int v;
        list<pair<int,int>> *l;
        bool directed;

        WeightedGraph(int v, bool directed=false){
            this->v = v;
            this->directed = directed;
            l = new list<pair<int,int>>[v];
        }

        void addEdge(int u, int v, int wt){
            l[u].push_back({v,wt});
            if(!directed){
                l[v].push_back({u,wt});
            }
        }

        void print(){
            for(int i=0; i<v; i++){
                cout<<i<<" --> ";
                for(auto v : l[i]){
                    cout<<v.first<<"("<<v.second<<"), ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};