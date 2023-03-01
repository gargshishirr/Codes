#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include<vector>

using namespace std;
/*
int nodes = 0;
int is3kiCycle(int i, unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj) {
  unordered_map<int, int> parent;
  parent[i] = -1;
  visited[i] = 1;
  queue<int> q;
  q.push(i);

  while (!q.empty()) {
    int front = q.front();
    nodes++;
    q.pop();

    for (auto neigh : adj[front]) {
      if (visited[neigh] == true && nodes==3) {
        //nodes++;
        cout<<"UYES";
        return 1;
        }
        else if(visited[neigh] == true && neigh != parent[front] && nodes!=3){
            nodes=0;
            //cout << "nYES";
            return 0;
        }
      else if (!visited[neigh]) {
        q.push(neigh);
        visited[neigh] = true;
        parent[neigh] = front;
        nodes++;
        //cout<<"Y"<<endl;
      }
      //nodes++;
    }
  }
  return 0;
}
int cylceDetection(vector<vector<int>> &edge, int n, int m) {
  unordered_map<int, list<int>> adj;
  int ans=0;
  for (int i = 0; i < m; i++) {
    int u = edge[i][0];
    int v = edge[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  unordered_map<int, bool> visited;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      ans = ans + is3kiCycle(i, visited, adj);
    }
  }
  return ans;
}

*/
void countCycles(vector<vector<bool>> &graph, vector<bool> &visited, int current, int start, int length, int& count) {
    visited[current] = true;

    // If a path of length 2 is found
    if(length == 0) {
        visited[current] = false;
        if(graph[current][start]) {
            count++;
            return;
        } else {
            return;
        }
    }

    for(int i = 0; i < graph.size(); i++) {
        if(!visited[i] and graph[current][i]) {
            countCycles(graph, visited, i, start, length - 1, count);
        }
    }

    visited[current] = false;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<bool>> graph(v, vector<bool>(v, false));

    // corner case
    if(e == 0) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;
        graph[first][second] = true;
        graph[second][first] = true;
    }

    vector<bool> visited(v, false);

    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            // For a 3 cycle from i we nee to find a path to vertex i of length 2
            countCycles(graph, visited, i, i, 2, count);
            visited[i] = true;
        }
    }

    // Since every path will be counted twice so we divide by 2
    cout << count / 2 << endl;
    return 0;

    // int n, e;
    // //cout << "Enter number of nodes";
    // cin >> n;
    // //cout << "Enter number of edges";
    // cin >> e;
    //
    // graph g;


    // //vector<vector<int>> graph;
    // for (int i = 0; i < e; i++) {
    //   vector<int> temp;
    //   int start, end;
    //   cin >> start >> end;
    //
    //   // temp.push_back(start);
    //   // temp.push_back(end);
    //   // graph.push_back(temp);
    // }
    // vector<bool> visited(n, false);

    // cout << cylceDetection(graph, n, e);
    // return 0;
}