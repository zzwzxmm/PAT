#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

long long convert(char *s, long long radix){
    long long n,sum=0;
    for(;*s;s++) {
        n=(*s>=97)?(*s-'a'+10):(*s-'0');
        if((LLONG_MAX-n)/radix<sum) return -1;
        sum=sum*radix+n;
    }
    return sum;
}

long long minradix(char *s){
    long long radix=1,n;
    for(;*s;s++){
        n=(*s>=97)?(*s-'a'+10):(*s-'0');
        radix=(radix>(n+1))?radix:(n+1);
    }
    return radix;
}

long long binsearch(long long min, long long max, char *a, long long n ){
    while(min<=max){
        long long mid=min+(max-min)/2;
        long long aval = convert(a,mid);
        if(aval>n || aval==-1){
            max=mid-1;
        } else if(aval<n){
            min=mid+1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(){
    char a[11],b[11],*p1,*p2;
    long long i,j,tag,radix,dec,radix2,min,max;
    scanf("%s %s %lld %lld",a,b,&tag,&radix);
    if(tag==1){
        p1=a;
        p2=b;
    } else if (tag==2){
        p2=a;
        p1=b;
    }

    dec=convert(p1,radix);
    min=minradix(p2);
    max=LLONG_MAX;
    if(strlen(p2)==1) radix2=minradix(p2);
    else radix2=binsearch(min,max,p2,dec);
    if(radix2==-1) printf("Impossible");
    else printf("%lld",radix2);
    return 0;
}
