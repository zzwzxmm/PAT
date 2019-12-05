#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
const int MAX=33;
struct node{
    int val;
    int lc,rc;
}data[MAX];
int post[MAX],in[MAX];
int n;

int createtree(int posl,int posr,int inl,int inr){
    if(posl>posr)
        return -1;
    int root=post[posr],position;
    data[root].val=root;
    for(int i=inl;i<=inr;i++){
        if(root==in[i]){
            position=i;
            break;
        }
    }
    int numleft=position-inl;
    data[root].lc=createtree(posl,posl+numleft-1,inl,position-1);
    data[root].rc=createtree(posl+numleft,posr-1,position+1,inr);
    return root;
}

void levelorder(int root){
    queue<node> q;
    q.push(data[root]);
    while(!q.empty()){
        node top=q.front();
        printf("%d",top.val);
        q.pop();
        if(top.lc!=-1) q.push(data[top.lc]);
        if(top.rc!=-1) q.push(data[top.rc]);
        if(q.empty()) printf("\n");
        else printf(" ");
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&post[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&in[i]);
    }
    int root=createtree(1,n,1,n);
    levelorder(root);
    return 0;
}
