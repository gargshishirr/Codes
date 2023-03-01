//
// Created by Shishir Garg on 04/01/23.
//
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void printBfs(vector<vector<int>> graph, int n, vector<int>& vis, int i)
{

    queue<int> que;
    que.push(i);
    vis[i] = 1;
    while(que.size()!=0)
    {
        int front = que.front();
        que.pop();
        cout<<front<<" ";
        vis[front] = 1;
        for(int i=0; i<n; i++)
        {
            if(graph[front][i] == 1 && vis[i]!=1)
            {
                vis[i] = 1;
                que.push(i);
            }
        }
    }
}
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i=0; i<m; i++)
    {
        int f, s;
        cin>>f>>s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++)
    {
        if(vis[i]!=1) printBfs(graph, n, vis, i);
    }

}