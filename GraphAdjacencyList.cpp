//
// Created by Shishir Garg on 27/01/23.
//
#include<unordered_map>
#include <list>

#include <iostream>
using namespace std;
class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int start, int end, bool directed) {
        adj[start].push_back(end);
        if (directed == false) {
            adj[end].push_back(start);
        }

    }

    void printAdjList() {
        for (auto i: adj) {
            cout << i.first << "-> ";
            for (auto j: i.second) {
                cout << j << ", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int e;
    cout<<"Enter the number of Edges"<<endl;
    cin>>e;
    int n;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;
    graph g;

    for(int i=0;i<e;i++){
        int u,v;
        bool dir;
        cin>>u>>v>>dir;
        g.addEdge(u,v,dir);
    }
    g.printAdjList();


return 0;
}