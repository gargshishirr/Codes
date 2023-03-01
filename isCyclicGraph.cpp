//
// Created by Shishir Garg on 27/01/23.
//
#include<unordered_map>
#include<list>
#include<queue>
#include <iostream>
using namespace std;
bool isCycle(int i, unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj  ){
    unordered_map<int, int> parent;
    parent[i]=-1;
    visited[i]=1;
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neigh: adj[front]){
            if(visited[neigh]==true && neigh!=parent[front]){
                return true;

            }
            else if(!visited[neigh]==true){
                q.push(neigh);
                visited[neigh]=true;
                parent[neigh]=front;

            }
        }
    }
    return false;

}
string cylceDetection(vector<vector<int>> &edge,int n, int m){
    unordered_map<int, list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edge[i][0];
        int v=edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCycle(i, visited, adj);
            if(ans==1){
                return "yes";
            }
        }
    }
    return "No";
}
class graph{
public:
    unordered_map<int,list<int>> adj;
    void addEdge(int start,int end, bool directed){
        adj[start].push_back(end);
        if(directed==true){
            adj[end].push_back(start);
        }
    }
};
int main(){
    int n,e;
    cout<<"Enter number of nodes";
    cin>>n;
    cout<<"Enter number of edges";
    cin>>e;
    graph g;
    vector<vector<int>> graph;
    for(int i=0;i<e;i++){
        vector<int> temp;
        int start,end;
        cin>>start>>end;
        temp.push_back(start);
        temp.push_back(end);
        graph.push_back(temp);
    }
    cout<<cylceDetection(graph,n,e);
return 0;
}