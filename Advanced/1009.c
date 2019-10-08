#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct poly{
    double coe;
    int exp;
}poly;

int main(){
    int k1,k2;
    int i,j,num;
    double val;
    scanf("%d",&k1);
    poly n1[k1];
    for(i=0;i<k1;i++){
        scanf("%d %lf",&num,&val);
        n1[i].coe=val;
        n1[i].exp=num;
    }
    scanf("%d",&k2);
    poly n2[k2];
    for(i=0;i<k2;i++){
        scanf("%d %lf",&num,&val);
        n2[i].coe=val;
        n2[i].exp=num;
    }
    double n3[2002]={0.0};
    for(i=0;i<k1;i++){
        for(j=0;j<k2;j++){
            num=n1[i].exp+n2[j].exp;
            n3[num]=n3[num]+n1[i].coe*n2[j].coe;
        }
    }
    int cnt=0;
    for(i=0;i<2002;i++){
        if(fabsf(n3[i])>1e-8) cnt++;
    }
    printf("%d ",cnt);
    j=0;
    for(i=2001;i>=0;i--){
        if(fabsf(n3[i])>1e-8) {
            j++;
            printf("%d %.1lf%c",i,n3[i],(j==cnt)?'\n':' ');
        }
        if(j==cnt) break;
    }
    return 0;
}
