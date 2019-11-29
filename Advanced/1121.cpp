#include<stdio.h>
using namespace std;
const int MAX=100010;
struct pair{
    int sp;
    int isin;
}cp[MAX];
int pres[MAX];
bool issingle[MAX]={false};

int main(){
    int n,m,a,b,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        cp[a].sp=b;
        cp[a].isin=0;
        cp[b].sp=a;
        cp[b].isin=0;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&c);
        pres[i]=c;
        cp[c].isin=1;
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        c=pres[i];
        int csp=cp[c].sp;
        if(cp[csp].isin==0) {
            issingle[c]=true;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    int cnt2=0;
    for(int i=0;i<MAX;i++){
        if(issingle[i]==true) {
            printf("%05d",i);
            cnt2++;
            if(cnt2==cnt) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
