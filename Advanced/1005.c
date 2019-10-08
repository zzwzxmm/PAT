#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char num[102];
    scanf("%s",num);
    int sum=0;
    char a[11][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int i;
    for(i=0;i<strlen(num);i++){
        sum+=(num[i]-'0');
    }
    int t=sum;
    int mask=1;
    while(sum>0){
        sum/=10;
        mask*=10;
    }
    sum=t;
    mask/=10;
//    printf("sum=%d mask=%d\n",sum,mask);
    if(sum==0) printf("zero");
    else {
        while(mask>=1){
            printf("%s%c",a[(sum/mask)],(mask==1)?'\n':' ');
            sum%=mask;
            mask/=10;
//            printf("sum=%d mask=%d\n",sum,mask);
        }
        
    }
    return 0;
}
