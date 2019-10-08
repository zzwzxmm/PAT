#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,j,k1,k2;
    float n1[1001]={0},n2[1001]={0},n3[1001]={0};
    scanf("%d",&k1);
    for(i=0;i<k1;i++){
        scanf("%d",&j);
        scanf("%f",&n1[j]);
    }
    scanf("%d",&k2);
    for(i=0;i<k2;i++){
        scanf("%d",&j);
        scanf("%f",&n2[j]);
    }
    int cnt=0;
    for(i=0;i<=1000;i++){
        n3[i]=n1[i]+n2[i];
        if(abs(n3[i])>=1e-8) cnt++;
    }
    printf("%d%c",cnt,(cnt==0)?'\n':' ');
    for(i=1000;i>=0;i--){
        if(abs(n3[i])>=1e-8) {
            cnt--;
            printf("%d %.1f%c",i,n3[i],(cnt==0)?'\n':' ');
        }
    }
    return 0;
}
