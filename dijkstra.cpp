
#include <iostream>
#include<climits>
using namespace std;
int findMinVertex(int *distance,bool *visited,int v){
    int min=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (min==-1 ||distance[i]<distance[min])){
            min=i;
        }
    }
    return min;
}
void djikstra(int **graph, int v){
    bool *visited=new bool[v];
    int *distance=new int[v];

    for(int i=0;i<v;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<v;i++){
        int minVertex=findMinVertex(distance,visited,v);
        visited[minVertex]=true;
        for(int j=0;j<v;j++){
            if(graph[minVertex][j]!=0 && !visited[j]){
                int dist=graph[minVertex][j]+distance[minVertex];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    int **graph=new int *[v];
    for(int i=0;i<v;i++){
        graph[i]=new int [v];
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int start,dest,weights;
        cin>>start>>dest>>weights;
        graph[start][dest]=weights;
        graph[dest][start]=weights;
    }
    cout<<endl;
    djikstra(graph,v);


return 0;
}