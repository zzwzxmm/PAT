#include<stdio.h>
#include<math.h>
using namespace std;
int isprime(int n){
    if (n<2) return 0;
    int flag=1;
    int m=sqrt(n*1.0);
    for(int i=2;i<=m;i++){
        if(n%i==0){
            flag=0;
            break;
        }
    }
    return flag;
}

int main(){
    int n,r;
    while(1){
        scanf("%d",&n);
        if(n<0) break;
        scanf("%d",&r);
        if(isprime(n)){
            int a[100],len=0;
            while(n){
                a[len++]=n%r;
                n/=r;
            }
            int n3=0;
            for(int i=0;i<len;i++){
                n3=n3*r+a[i];
            }
            if(isprime(n3)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        } else {
            printf("No\n");
        }
    }
    return 0;
}
