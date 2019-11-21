#include<stdio.h>
int main(){
    double a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    double profit;
    double b[3];
    for(int i=0;i<3;i++){
        if(a[i][0]>a[i][1] && a[i][0]>a[i][2]) {
            printf("W ");
            b[i]=a[i][0];
        }
        else if(a[i][1]>a[i][0] && a[i][1]>a[i][2]) {
            printf("T ");
            b[i]=a[i][1];
        }
        else if(a[i][2]>a[i][0] && a[i][2]>a[i][1]) {
            printf("L ");
            b[i]=a[i][2];
        }
    }
    profit=(b[0]*b[1]*b[2]*0.65-1)*2;
    printf("%.2lf",profit);
    return 0;
}
