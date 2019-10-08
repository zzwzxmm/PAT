#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char a[20],b[20];
    long long i,j,tag,radix,flag,dec,dec2,min;
    scanf("%s %s %lld %lld",a,b,&tag,&radix);
    if(tag==1){
        flag=0;
        dec=0;
        for(j=0;j<strlen(a);j++){
            if((a[j]-'0')<=9) dec=dec*radix+(a[j]-'0');
            else if((a[j]-'a')>=0) dec=dec*radix+(a[j]-'a'+10);
        }
        for(i=1;i<=100;i++){
            dec2=0;
            min=0;
            for(j=0;j<strlen(b);j++){
                if((b[j]-'0')<=9) {
                    dec2=dec2*i+(b[j]-'0');
                    if((b[j]-'0')>min-1) min=b[j]-'0'+1;
                }
                else if((b[j]-'a')>=0) {
                    dec2=dec2*i+(b[j]-'a'+10);
                    if((b[j]-'a')>min-1) min=b[j]-'a'+1;
                }
            }
            if(dec==dec2 && min<=i) {
                flag=1;
                printf("%lld",i);
                break;
            }
        }
        if(flag==0) printf("Impossible");
    } else if(tag==2){
        flag=0;
        dec=0;
        for(j=0;j<strlen(b);j++){
            if((b[j]-'0')<=9) dec=dec*radix+(b[j]-'0');
            else if((b[j]-'a')>=0) dec=dec*radix+(b[j]-'a'+10);
        }
        for(i=1;i<=100;i++){
            dec2=0;
            min=0;
            for(j=0;j<strlen(a);j++){
                if((a[j]-'0')<=9) {
                    dec2=dec2*i+(a[j]-'0');
                    if((a[j]-'0')>min-1) min=a[j]-'0'+1;
                }
                else if((a[j]-'a')>=0) {
                    dec2=dec2*i+(a[j]-'a'+10);
                    if((a[j]-'a')>min-1) min=a[j]-'a'+1;
                }
            }
            if(dec==dec2 && min<=i) {
                flag=1;
                printf("%lld",i);
                break;
            }
        }
        if(flag==0) printf("Impossible");
    }
    return 0;
}
