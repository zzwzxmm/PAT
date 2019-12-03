#include<stdio.h>
#include<vector>
using namespace std;
const int MAX=100010;
vector<int> pre;
struct node{
    int add,val,next;
}data[MAX];

int main(){
    int n,k,s;
    scanf("%d%d%d",&s,&n,&k);
    for(int i=0;i<n;i++){
        int a,v,n;
        scanf("%d%d%d",&a,&v,&n);
        data[a].add=a;
        data[a].val=v;
        data[a].next=n;
    }
    for(int add=s;add!=-1;){        
        if(data[add].val<0) {
            pre.push_back(add);
        }
        add=data[add].next;
    }
    for(int add=s;add!=-1;){
        if(data[add].val<=k && data[add].val>=0){
            pre.push_back(add);
        }
        add=data[add].next;
    }
    for(int add=s;add!=-1;){
        if(data[add].val>k){
            pre.push_back(add);
        }
        add=data[add].next;
    }
    for(int i=0;i<pre.size()-1;i++){
        printf("%05d %d %05d\n",pre[i],data[pre[i]].val,pre[i+1]);
    }
    printf("%05d %d -1",pre[pre.size()-1],data[pre[pre.size()-1]].val);
    return 0;
}
