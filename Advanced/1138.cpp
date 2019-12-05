#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
const int MAX=1000010;
struct node{
    int id;
    int lc,rc;
}data[MAX];
int preorder[MAX],inorder[MAX];
int n;
vector<int> ans;

int createtree(int prel,int prer,int inl,int inr){
    if(prel>prer){
        return -1;
    }else{
        int root=preorder[prel];
        data[root].id=root;
        int position;
        for(int i=inl;i<=inr;i++){
            if(inorder[i]==root) {
                position=i;   
                break;
            }
        }
        int numleft=position-inl;
        data[root].lc=createtree(prel+1,prel+numleft,inl,inl+numleft-1);
        data[root].rc=createtree(prel+numleft+1,prer,inl+numleft+1,inr);
        return root;
    }
}

void postorder(int root){
    if(data[root].lc!=-1) postorder(data[root].lc);
    if(data[root].rc!=-1) postorder(data[root].rc);
    ans.push_back(data[root].id);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&preorder[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&inorder[i]);
    }
    int root=createtree(1,n,1,n);
    postorder(root);
    printf("%d",ans[0]);
    return 0;
}
