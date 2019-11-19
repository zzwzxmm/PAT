#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

//Using vector node as adjacency table
struct node{
    int v;
    int dis;
};

//Variables  define num[max] to count, num[max]=num[now]+num[pre] or num[pre];
//Using t[max] and w[max] to store maximum weight
const int MAX=500;
const int INF=1000000000;
vector<node> adj[MAX];
int t[MAX]={0};
int w[MAX]={0};
bool vis[MAX]={false};
int d[MAX];
int n,m;
int num[MAX];

//dijkstra algorithm
void dijkstra(int s){
    fill(d,d+MAX,INF);
    fill(num,num+MAX,INF);
    d[s]=0;
    num[s]=1; //initialize num;
    t[s]=w[s];  //initialize t;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return; // all visited;
        vis[u]=true;
        // update distance and weight, and count num;
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            if(vis[v]==false && d[u]+adj[u][j].dis<d[v]){
                d[v]=d[u]+adj[u][j].dis;
                t[v]=t[u]+w[v];
                num[v]=num[u];
            } else if(d[u]+adj[u][j].dis == d[v]){
                if(w[v]+t[u]>t[v]) t[v]=t[u]+w[v];
                num[v]+=num[u];
            }
        }
    }
}

int main(){
    int s,dest;
    scanf("%d%d%d%d",&n,&m,&s,&dest);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    int city1,city2,l;
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&city1,&city2,&l);
        node test;
        test.v=city2;
        test.dis=l;
        adj[city1].push_back(test); //push one node in city1;
        test.v=city1;
        test.dis=l;
        adj[city2].push_back(test); //push one node in city2; MUST!!! if not, something will be wrong;
    }
    dijkstra(s);
    printf("%d %d",num[dest],t[dest]);
    return 0;
}
