#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    if (n<=1000){
        while(n!=1){
            if (n%2==0){
                n=n/2;
            } else {
                n=(n*3+1)/2;
            }
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
