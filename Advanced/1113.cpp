#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
const int MAX=100010;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int dn,dsum=0;
    if(n%2==0){
        dn=0;
        for(int i=0;i<n/2;i++){
            dsum+=a[i];
        }
        for(int i=n/2;i<n;i++){
            dsum-=a[i];
        }
    }else{
        dn=1;
        for(int i=0;i<(n+1)/2;i++){
            dsum+=a[i];
        }
        for(int i=(n+1)/2;i<n;i++){
            dsum-=a[i];
        }
    }
    printf("%d %d",dn,dsum);
    return 0;
}
