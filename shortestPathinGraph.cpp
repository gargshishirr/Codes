//
// Created by Shishir Garg on 29/01/23.
//
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int v, int e, int start,
                         int end) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(start);
    parent[start] = -1;
    visited[start] = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    vector<int> ans;
    vector<int> temp;
    int current = end;
    ans.push_back(current);

    while (current != start) {
        current = parent[current];
        ans.push_back(current);
    }
    // reverse(ans.begin(), ans.end());
    if(ans.size()==2){
        return temp;
    }
    return ans;


}
int main() {
    int n, e;
    //cout << "Enter number of nodes";
    cin >> n;
    //cout << "Enter number of edges";
    cin >> e;
    // graph g;
    vector<pair<int, int>> graph;
    for (int i = 0; i < e; i++) {
        // vector<int> temp;
        int start, end;
        pair<int, int> temp;

        cin >> start >> end;
        temp.first = start;
        temp.second = end;
        graph.push_back(temp);
    }
    // cout<<cylceDetection(graph,n,e);
    int start, end;
    cin >> start >> end;
    vector<int> ans = shortestPath(graph, n, e, start, end);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}