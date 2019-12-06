#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
    int data,height;
    node *left,*right;
};

int geth(node* root){
    if(root==NULL) return 0;
    else return root->height;
}

void updateh(node* root){
    root->height=max(geth(root->left),geth(root->right))+1;
}

void L(node* &root){
    node *tmp=root->right;
    root->right=tmp->left;
    tmp->left=root;
    updateh(root);
    updateh(tmp);
    root=tmp;
}

void R(node* &root){
    node *tmp=root->left;
    root->left=tmp->right;
    tmp->right=root;
    updateh(root);
    updateh(tmp);
    root=tmp;
}

int getbf(node* root){
    return geth(root->left)-geth(root->right);
}

void insert(node* &root, int data){
    if(root==NULL){
        root=new node;
        root->data=data;
        root->height=1;
        root->left=root->right=NULL;
        return;
    }
    if(data<root->data) {
        insert(root->left,data);
        updateh(root);
        if(getbf(root)==2){
            if(getbf(root->left)==1){
                R(root);
            }else if(getbf(root->left)==-1){
                L(root->left);
                R(root);
            }
        }
    }
    else {
        insert(root->right,data);
        updateh(root);
        if(getbf(root)==-2){
            if(getbf(root->right)==-1){
                L(root);
            }else if(getbf(root->right)==1){
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    int n,data;
    node* root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(root,data);
    }
    printf("%d",root->data);
    return 0;
}
