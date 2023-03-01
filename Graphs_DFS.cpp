//
// Created by Shishir Garg on 04/01/23.
//

#include <iostream>
using namespace std;

int DFS(int **arr,int n,int start, bool*output){
    cout<<start<<"->";
    output[start]=true;
    //cout<<endl;
    for(int i=0;i<n;i++){
        if(i==start){
            continue;
        }
        if(arr[start][i]==1){
            if(output[i]) {
                continue;
            }
            DFS(arr,n,i,output);

        }
    }

}
int main(){
    int n,e;
    cin>>n>>e;

    int **edges=new int *[n];
    for(int i=0;i<n;i++){
        edges[i]=new int [n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int firstvertex,secondvertex;
        cin>>firstvertex>>secondvertex;
        edges[firstvertex][secondvertex]=1;
        edges[secondvertex][firstvertex]=1;
    }
    bool *visited=new bool [n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    DFS(edges,n,0,visited);
    delete [] visited;
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;

}
