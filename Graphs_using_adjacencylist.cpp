//
// Created by Shishir Garg on 08/01/23.
//
#include<queue>
#include<vector>
#include <iostream>
using namespace std;
vector<int> BFS(int v,vector<int> adj[]){
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    visited[0]=true;
    queue<int> q;
    q.push(0);
    vector<int>bfstemp;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        bfstemp.push_back(temp);

        for(auto it : adj[temp]){
            if(visited[it]==false){
                visited[it]=true;
                q.push(it);

            }
        }
    }
    return bfstemp;
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int> adj[vertices];
    for(int i=0;i<edges;i++){
        int start,end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    //BFS(vertices,adj);
    vector<int>ans= BFS(vertices,adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";

    }
    cout<<endl;








return 0;
}
