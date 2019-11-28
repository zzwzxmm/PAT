#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
const int MAX=22;
struct node{
    int id;
    int lc,rc;
}data[MAX];
int n,maxi=0,maxnode;
bool vis[MAX]={false};

void dfs(int r,int index){
    if(index>maxi){
        maxi=index;
        maxnode=data[r].id;
    }
    if(data[r].lc!=-1) dfs(data[r].lc,index*2);
    if(data[r].rc!=-1) dfs(data[r].rc,index*2+1);
    return;
}

int main(){
    scanf("%d",&n);
    string s1,s2;
    for(int i=0;i<n;i++){
        cin >> s1 >> s2;
        data[i].id=i;
        if(s1!="-") data[i].lc=stoi(s1);
        else data[i].lc=-1;
        if(s2!="-") data[i].rc=stoi(s2);
        else data[i].rc=-1;
    }
    int r;
    for(int i=0;i<n;i++){
        if(data[i].lc!=-1) vis[data[i].lc]=true;
        if(data[i].rc!=-1) vis[data[i].rc]=true;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==false) {
            r=i;
            break;
        }
    }
    dfs(r,1);
    if(maxi!=n){
        printf("NO %d",r);
    } else {
        printf("YES %d",maxnode);
    }
    return 0;
}
