#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int sum=a[0];
    for(int i=1;i<n;i++){
        sum=(sum+a[i])/2;
    }
    printf("%d",sum);
    return 0;
}
