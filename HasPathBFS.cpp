//
// Created by Shishir Garg on 07/01/23.
//
//
// Created by Shishir Garg on 04/01/23.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool printBfs(vector<vector<int>> graph, int n, vector<int> &vis,int destination,int source) {
    queue<int> que;
    que.push(source);
    vis[source]=1;

    while(que.size()!=0){
        int front=que.front();
        que.pop();
        if(front==destination)
            return true;
        for(int i=0;i<n;i++){
            if(graph[front][i]==1 && vis[i]!=1){
                que.push(i);
            }
        }
    }
    return false;
}
int main() {
    int n, m; // Edges=m    vertices=n
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int f, s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    vector<int> vis(n, 0);
    int source,dest;
    cin>>source>>dest;
    bool ans= printBfs(graph, n, vis, dest,source);
    if(ans==true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}