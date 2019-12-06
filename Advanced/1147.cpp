#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX=1010;
struct node{
    int data;
    int lc,rc;
}data[MAX];
int n,m,ismax,ismin;
vector<int> ans;

void createtree(int a[]){
    int i=1;
    while(i<=m){
        data[i].data=a[i];
        if(i*2<=m) data[i].lc=i*2;
        else data[i].lc=-1;
        if(i*2+1<=m) data[i].rc=i*2+1;
        else data[i].rc=-1;
        i++;
    }
}

void postorder(int root,vector<int> &v){
    if(root==-1) return;
    if(data[root].lc!=-1) postorder(data[root].lc,v);
    if(data[root].rc!=-1) postorder(data[root].rc,v);
    v.push_back(data[root].data);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int a[m+1];
        fill(a,a+m+1,0);
        ans.clear();
        ismax=ismin=1;
        for(int j=1;j<=m;j++){
            scanf("%d",&a[j]);
        }
        int root=1;
        createtree(a);
        postorder(root,ans);
        for(int j=2;j<=m;j++){
           if(a[j]>a[j/2]) ismax=0;
           else if(a[j]<a[j/2]) ismin=0;
        } 
        if(ismax){
            printf("Max Heap\n");
        } else if(ismin) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        for(int j=0;j<m;j++){
            printf("%d%c",ans[j],(j==m-1)?'\n':' ');
        }
    }
    return 0;
}
