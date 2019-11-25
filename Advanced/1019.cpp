#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int main(){
    long a,b;
    scanf("%ld%ld",&a,&b);
    long c[1000];
    fill(c,c+1000,-1);
    int tmp=a;
    int cnt=0;
    while(tmp>=b){
        tmp/=b;
        cnt++;
    }
    int max=cnt;
    while(cnt>0){
        int t=a/pow(b,cnt);
        if(a-t*pow(b,cnt)==a){
            cnt--;
            c[cnt]=0;
            continue;
        }else{
            a=a-t*pow(b,cnt);
            c[cnt]=t;
        }
    }
    c[0]=a;
    int flag=1;
    for(int i=0,j=max;i<=j;i++,j--){
        if(c[i]!=c[j]){
            flag=0;
            break;
        }
    }
    if(flag){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i=max;i>=0;i--){
        printf("%ld%c",c[i],(i==0)?'\n':' ');
    }
    return 0;
}
