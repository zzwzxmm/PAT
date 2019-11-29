#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
    int u;
    int v;
};

int main(){
    int n,k,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        node a[k+1];
        int flag=1;
        for(int j=1;j<=k;j++){
            scanf("%d",&m);
            a[j].u=j;
            a[j].v=m;
        }
        for(int j=1;j<=k-1;j++){
            for(int l=j+1;l<=k;l++){
                if(abs(a[j].u-a[l].u)==abs(a[j].v-a[l].v)) {
                    flag=0;
                    goto loop;
                }
                if(a[j].u==a[l].u || a[j].v==a[l].v) {
                    flag=0;
                    goto loop;
                }
            }
        }
        loop:
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
