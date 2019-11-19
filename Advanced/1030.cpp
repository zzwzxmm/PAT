#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
//Using dijkstra+DFS, can also use dijkstra only;
//Using vector to store adjacency table;
struct node{
    int v;
    int dis;
};
const int MAX=500;
const int INF=1000000000;
int n,m,s,dest;
vector<int> pre[MAX]; //store previous vetices;
vector<int> path,tmppath;  //store path;
int totalcost=INF,d[MAX],cost[MAX][MAX];  //adjacency matrix to store cost;
bool vis[MAX]={false};
vector<node> adj[MAX];

//dijkstra algorithm
void dijkstra(int s){
    fill(d,d+MAX,INF);    //IMPORTANT!!! Initialization of array, must using memset or fill, fill better;
    d[s]=0;               //Otherwise the d[MAX] is not right at the beginning;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int v=0;v<n;v++){
            if(vis[v]==false && d[v]<MIN){
                u=v;
                MIN=d[v];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            if(vis[v]==false && d[v]>d[u]+adj[u][j].dis) {
                d[v]=d[u]+adj[u][j].dis;
                pre[v].clear();
                pre[v].push_back(u);
            } else if(vis[v]==false && d[v]==d[u]+adj[u][j].dis) {
                pre[v].push_back(u);
            }
        }
    }
}

//Depth first search
void DFS(int v){
    if(v==s){
        tmppath.push_back(v);
        int tmpcost=0;
        for(int i=1;i<tmppath.size();i++){
            int city1=tmppath[i-1];
            int city2=tmppath[i];
            tmpcost+=cost[city1][city2];
        }
        if(tmpcost<totalcost){
            path=tmppath;
            totalcost=tmpcost;
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    tmppath.pop_back();
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&dest);
    int city1,city2,dis,c;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&city1,&city2,&dis,&c);
        node input;
        input.dis = dis;
        input.v = city1;
        adj[city2].push_back(input);
        input.v = city2;
        adj[city1].push_back(input);
        cost[city1][city2]=c;
        cost[city2][city1]=c;
    }
    dijkstra(s);
    DFS(dest);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("%d %d",d[dest],totalcost);
    return 0;
}
