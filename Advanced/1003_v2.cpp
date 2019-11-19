#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int MAX=500;
const int INF= 1000000000;
int n,m;
int g[MAX][MAX],d[MAX],weight[MAX],sum[MAX],num[MAX];
bool vis[MAX]={false};

void dijkstra(int s){
    num[s]=1;
    d[s]=0;
    sum[s]+=weight[s];
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false && g[u][v]!=INF){
                if(g[u][v]+d[u]<d[v]){
                    d[v]=g[u][v]+d[u];
                    num[v]=num[u];
                    sum[v]=sum[u]+weight[v];
                } else if(vis[v]==false && g[u][v]+d[u]==d[v]){
                    num[v]+=num[u];
                    if(sum[v]<sum[u]+weight[v]) sum[v]=sum[u]+weight[v];
                }
            }
        }
    }
}

int main(){
    int s,dest;
    scanf("%d%d%d%d",&n,&m,&s,&dest);
    //NOTE!!!Fill and Memset!
    memset(weight,0,sizeof(weight));
    memset(sum,0,sizeof(sum));
    fill(d,d+MAX,INF);
    memset(num,0,sizeof(num));
    fill(g[0],g[0]+MAX*MAX,INF);
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    int city1,city2,l;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&city1,&city2,&l);
        g[city1][city2]=l;
        g[city2][city1]=l;
    }
    dijkstra(s);
    printf("%d %d",num[dest],sum[dest]);
    return 0;
}
