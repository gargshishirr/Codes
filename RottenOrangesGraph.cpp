//
// Created by Shishir Garg on 08/01/23.
//
#include<queue>
#include <iostream>
#include<vector>
using namespace std;
int Rotten(vector<vector<int>> &grid){
    int n=grid.size();
    int m= grid[0].size();
    //{{r,c},t}

    queue <pair <pair<int,int> ,int>>q;
    int visited[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }
            else{
                visited[i][j]=0;
            }
        }
    }
    int time=0;
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        time=max(t,time);
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                visited[nrow][ncol]=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return time;
}
int main(){
    int n, m; // Edges=m    vertices=n
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    int ans= Rotten(graph);
    cout<<ans;

return 0;
}
