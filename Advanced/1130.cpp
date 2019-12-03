#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
const int MAX=22;
int n;
//bool vis[n]={false};
int isroot[MAX];
struct node{
    string s;
    int lc,rc;
}data[MAX];

void inorder(int r){
    int lc=data[r].lc,rc=data[r].rc;
    if(lc!=-1){
        if(data[lc].lc!=-1 || data[lc].rc!=-1) cout <<"(";
        inorder(data[r].lc);
        if(data[lc].lc!=-1 || data[lc].rc!=-1) cout <<")";
    }
    cout << data[r].s;
    if(rc!=-1){
        if(data[rc].lc!=-1 || data[rc].rc!=-1) cout <<"(";
        inorder(data[r].rc);
        if(data[rc].lc!=-1 || data[rc].rc!=-1) cout <<")";
    }
}

int main(){
    scanf("%d",&n);
    string s;
    int l,r;
    fill(isroot,isroot+n,1);
    for(int i=0;i<n;i++){
        cin >> s;
        scanf("%d%d",&l,&r);
        data[i].s=s;
        if(l!=-1) {
            data[i].lc=l-1;
            isroot[l-1]=0;
        } else data[i].lc=-1;
        if(r!=-1) {
            data[i].rc=r-1;
            isroot[r-1]=0;
        } else data[i].rc=-1;
    }
    int root;
    for(int i=0;i<n;i++){
        if(isroot[i]==1) root=i;
    }
    inorder(root);
    return 0;
}
