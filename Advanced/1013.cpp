#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//此题考BFS，DFS，或者并查集
//Using adjacency matrix or table(vector);
const int INF=100000000;
const int MAX=1000;
bool vis[MAX] = {false};
int g[MAX][MAX];
int origin[MAX][MAX];
int n,m,k;
//Depth first search method (also can be done using Breadth first search);
//even use UnionFindSet;
void DFS(int u){
    vis[u] = true;
    for(int v=1; v<=n; v++){
        if(vis[v] == false && g[u][v] != INF) {
            DFS(v);
        }
    }
}
//DFS traverse;
int DFStraverse(int city){
    // Use cnt to count the numbers of sets;
    int cnt=0;
    for(int u=1;u<=n;u++){
        if(vis[u] == false && u!=city) {
            cnt++;
            DFS(u);
        }
    }
    return cnt-1;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    // Initialization;
    fill(origin[0],origin[0]+MAX*MAX,INF);
    fill(g[0],g[0]+MAX*MAX,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        origin[u][v]=1;
        origin[v][u]=1;
    }
    int city;
    // For each city;
    for(int i=0;i<k;i++){
        scanf("%d",&city);
        // Initialize vis[] and g[][];
        for(int j=1;j<=n;j++){
            vis[j] = false;
        }
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                g[j][l]=origin[j][l];
            }
        }
        // break highways;
        for(int j=1;j<=n;j++){
            g[city][j]=INF;
            g[j][city]=INF;
        }
        // count sets;
        int times=DFStraverse(city);
        printf("%d\n",times);
    }
    return 0;
}
