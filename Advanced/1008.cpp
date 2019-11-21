#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n+1],sum=0;
    a[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[i-1]) sum=sum+5+6*(a[i]-a[i-1]);
        else sum=sum+5+4*(a[i-1]-a[i]);
    }
    printf("%d",sum);
    return 0;
}
