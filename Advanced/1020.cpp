#include<stdio.h>
#include<queue>
using namespace std;

int n,post[31],in[31];

struct node{
    int key;
    node* lchild;
    node* rchild;
};

node* create(int postL, int postR, int inL, int  inR){
    if(postL>postR) return NULL;
    node* root = new node;
    root->key = post[postR];
    int k;
    for(k=inL;k<=inR;k++) {
        if(in[k]==post[postR]) break;
    }
    int numleft = k-inL;
    root->lchild = create(postL,postL+numleft-1,inL,k-1);
    root->rchild = create(postL+numleft,postR-1,k+1,inR);
    return root;
}

int cnt=0;

void BFS(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        cnt++;
        printf("%d",top->key);
        if(cnt<n) printf(" ");
        if(top->lchild != NULL) q.push(top->lchild);
        if(top->rchild != NULL) q.push(top->rchild);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    node* root = create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}
