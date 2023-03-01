//
// Created by Shishir Garg on 29/01/23.
//
#include<vector>
#include<unordered_map>
#include <list>
#include <iostream>
#include<queue>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,list<int> >adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}
int main(){
    int n,e;
    cout<<"Enter number of nodes";
    cin>>n;
    cout<<"Enter number of edges";
    cin>>e;
    vector<vector<int>> graph;
    for(int i=0;i<e;i++){
        int start,end;
        cin>>start>>end;
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        graph.push_back(temp);
    }
    vector<int>ans= topologicalSort(graph,n,e);
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    return 0;
}