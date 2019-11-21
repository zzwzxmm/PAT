#include<stdio.h>
#include<algorithm>
using namespace std;

// dynamic planning
// biggest continuous subsequence
const int MAX=10010;
int k,a[MAX];

int main(){
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    int m[k],mi=0,big;
    m[0]=a[0];
    big=m[0];
    for(int i=1;i<k;i++){
        m[i]=max(m[i-1]+a[i],a[i]);
        if(m[i]>m[i-1] && big<m[i]) { // big<m[i] update mi
            mi=i;
            big=m[i];
        } 
    }
    int n[k],si=0;
    n[k-1]=a[k-1];
    for(int i=k-1;i>0;i--){
        n[i-1]=max(n[i]+a[i-1],a[i-1]);
        if(n[i-1]>n[i] && n[i-1]==big){ //big==n[i-1] update si
            si=i-1;
        }
    }
    if(big<0){
        printf("0 %d %d",a[0],a[k-1]);
    }else{
        printf("%d %d %d",big,a[si],a[mi]);
    }
    return 0;
}
