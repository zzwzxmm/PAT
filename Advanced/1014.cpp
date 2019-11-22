#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=1000000000;
const int MAX=1010;
struct node{
    int cid;
    int tr;
    int et;
}N[MAX];

int main(){
    int n,m,k,a;
    scanf("%d%d%d%d",&n,&m,&k,&a);
    int minute;
    queue<node> q[n];
    queue<node> cust;
    for(int i=1;i<=k;i++){
        scanf("%d",&minute);
        N[i].cid=i;
        N[i].tr=minute;
        cust.push(N[i]);
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(!cust.empty()) {
                node front = cust.front();
                cust.pop();
                q[i].push(front);
            } else {
                break;
            }
        }
    }
    int sum[n];
    fill(sum,sum+n,480);
    while(1){
        int s=INF,window=0;
        for(int i=0;i<n;i++){
            if(!q[i].empty()){
                if (q[i].front().tr+sum[i]<s) {
                    s=q[i].front().tr+sum[i];
                    window=i;
                }
            } 
        }
        if(s==INF) break;
        node fast=q[window].front();
        q[window].pop();
        if(!cust.empty()){
            q[window].push(cust.front());
            cust.pop();
        }
        sum[window]=sum[window]+fast.tr;
        N[fast.cid].et=sum[window];
    }
    for(int i=0;i<a;i++){
        int ask;
        scanf("%d",&ask);
        int h = N[ask].et/60;
        int m = N[ask].et%60;
        if((h==17 && m>0) || (h>17)) {
            printf("Sorry\n");
        }else{
            printf("%02d:%02d\n",h,m);
        }
    }
    return 0;
}
