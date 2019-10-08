#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a+b;
    if(c<0) {
        printf("-");
        c=-c;
    }
    if(c>=1000000) {
        printf("%d,%03d,%03d",c/1000000,(c%1000000)/1000,(c%1000));
    } else if(c>=1000) {
        printf("%d,%03d",c/1000,(c%1000));
    } else {
        printf("%d",c);
    }
    return 0;
}
