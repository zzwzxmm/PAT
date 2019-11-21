#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
//BFS traverse; Tree! level in node structure.
const int MAX=100;
int n,m;
bool inq[MAX]={false};
struct node{
    vector<int> child;
    int level;
}tree[MAX];
int cnt[MAX],maxlevel=0;

//BFS change level;
void BFS(int root){
    queue<node> q;
    q.push(tree[root]);
    tree[root].level=0;
    inq[root]=true;
    while(!q.empty()){
        node top=q.front();
        q.pop();
        for(int i=0;i<top.child.size();i++){
            int c=top.child[i];
            if(inq[c]==false){
                tree[c].level=top.level+1;
                if(tree[c].level>maxlevel) maxlevel=tree[c].level;
                inq[c]=true;
                q.push(tree[c]);  // Note!!! push after level change!!! otherwise level=0
            }
        }
        if (top.child.size()==0) {
                cnt[top.level]+=1;
        }
    }
    return;
}

//BFS traverse. If only one tree, no need indeed.
void BFStraverse(){
    for(int i=1;i<=n;i++){
        if(inq[i]==false) BFS(i);
    }
    return;
}

int main(){
    scanf("%d%d",&n,&m);
    fill(cnt,cnt+MAX,0);
    for(int i=0;i<m;i++){
        int id,k,cid;
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&cid);
            tree[id].child.push_back(cid);
        }
    }
    BFStraverse();
    for(int i=0;i<maxlevel;i++){
        printf("%d ",cnt[i]);
    }
    printf("%d",cnt[maxlevel]);
 // printf("%d%c",cnt[i],(i==maxlevel)?'\n':' ');
 // NOTE!!! '\n' not "\n", char type,not string.
    return 0;
}
