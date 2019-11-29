#include<stdio.h>
#include<set>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    set<int> fi;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        int sum=0;
        while(a[i]){
            sum+=a[i]%10;
            a[i]/=10;
        }
        fi.insert(sum);
    }
    set<int>::iterator it=fi.begin();
    printf("%d\n",fi.size());
    printf("%d",*it);
    it++;
    for(;it!=fi.end();it++){
        printf(" %d",*it);
    }
    printf("\n");
    return 0;
}
