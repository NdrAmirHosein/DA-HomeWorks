# include <iostream>
# include <vector>
# include <list>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    private:
    vector<vector<int>> adjList;
    bool isDierect;

    void dfs(int node, vector<bool>& visited, list<int>& topolist){
        visited[node] = true;

        for (int v : adjList[node]){
            if (!visited[v]){
                dfs(v, visited, topolist);
            }
        }
        topolist.push_front(node);
    }


    public:
    Graph(int vertices, bool directed=true){
        adjList.resize(vertices);
        isDierect = directed;
    }

    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        
        if (!isDierect){
            adjList[dest].push_back(src);
        }
    }

    void printGraph(){
        for (int i = 0; i < adjList.size(); i++){
            cout << "adj list for node" << i << ":";
            for (int j = 0 ; j < adjList[i].size(); j++){
                cout << adjList[i][j] << endl;
            }
            cout << endl;
        }
    }

    list<int> toposort(){
        int v = adjList.size();
        vector<bool> visited(v, false);
        list<int> topolList;

        for (int i = 0; i < v; i++){
            if (!visited[i]){
                dfs(i, visited, topolList);
            }
        }

        return topolList;
    }

    void longestPathDAG(int start){
        int v = adjList.size();
        list<int> topoOerder = toposort();
        vector<int> dist(v, -1);
        dist[start] = 0;

        for(int v : topoOerder){
            if (dist[v] != -1){
                for( int u : adjList[v]){
                    if (dist[u] < dist[v] + 1){
                        dist[u] = dist[v] + 1;
                    }
                }
            }
        }

        cout << *max_element(dist.begin(), dist.end());
    }

};

int main(){

    int vertices = 6;
    Graph directedGraph(vertices);
    directedGraph.addEdge(0, 1),
    directedGraph.addEdge(0, 3);
    directedGraph.addEdge(0, 4);
    directedGraph.addEdge(1, 4);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(2, 0);
    directedGraph.addEdge(2, 1);
    directedGraph.addEdge(4, 3);
    directedGraph.addEdge(5, 0);
    directedGraph.addEdge(5, 2);

//  The longest path in this graph is 5 and the return value of the code is 5



    list<int>topoOrder =  directedGraph.toposort();

    directedGraph.longestPathDAG(topoOrder.front());

    return 0;
};
