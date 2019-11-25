#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
const int MAX=11;
int n,cnt;
struct node{
    int f,lc,rc;
};
node data[MAX];

int findfather(int a){
    if(data[a].f==a) return a;
    else {
        findfather(data[a].f);
    }
}

void levelorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cnt++;
        printf("%d%c",top,(cnt==n)?'\n':' ');
        if(data[top].lc!=-1) q.push(data[top].lc);
        if(data[top].rc!=-1) q.push(data[top].rc);
    }
    return;
}

void inorder(int root){
    if(data[root].lc!=-1) inorder(data[root].lc);
    cnt++;
    printf("%d%c",root,(cnt==n)?'\n':' ');
    if(data[root].rc!=-1) inorder(data[root].rc);
    return;
}

int main(){
    scanf("%d",&n);
    char c1,c2;
    for(int i=0;i<n;i++) {
        data[i].f=i;
        data[i].lc=-1;
        data[i].rc=-1;
    }
    for(int i=0;i<n;i++){
        scanf(" %c %c",&c1,&c2);
        if(c1!='-') {
            data[i].rc=c1-'0';
            data[c1-'0'].f=i;
        }
        if(c2!='-') {
            data[i].lc=c2-'0';
            data[c2-'0'].f=i;
        }
    }
    int root = findfather(0);
    cnt=0;
    levelorder(root);
    cnt=0;
    inorder(root);
    return 0;
}
