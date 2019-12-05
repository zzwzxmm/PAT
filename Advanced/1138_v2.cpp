#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
const int MAX=50010;
struct node{
    int id;
    node* lc;
    node* rc;
};
int pre[MAX],in[MAX];
int n;
vector<int> ans;

node* createtree(int prel,int prer,int inl,int inr){
    if(prel>prer){
        return NULL;
    }else{
        node* root=new node;
        root->id=pre[prel];
        int position;
        for(int i=inl;i<=inr;i++){
            if(in[i]==pre[prel]) {
                position=i;   
                break;
            }
        }
        int numleft=position-inl;
        root->lc=createtree(prel+1,prel+numleft,inl,inl+numleft-1);
        root->rc=createtree(prel+numleft+1,prer,inl+numleft+1,inr);
        return root;
    }
}

void postorder(node *root){
    if(root->lc!=NULL) postorder(root->lc);
    if(root->rc!=NULL) postorder(root->rc);
    ans.push_back(root->id);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    node* root=createtree(0,n-1,0,n-1);
    postorder(root);
    printf("%d",ans[0]);
    return 0;
}
