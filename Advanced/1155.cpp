#include<stdio.h>
#include<vector>
using namespace std;
const int MAX=1010;
vector<int> v;
int n,a[MAX];

void dfs(int index){
    if(index*2>n && index*2+1>n){
        if(index<=n){
            for(int i=0;i<v.size();i++){
                printf("%d%c",v[i],(i==v.size()-1)?'\n':' ');
            }
        }
    } else {
        v.push_back(a[index*2+1]);
        dfs(index*2+1);
        v.pop_back();
        v.push_back(a[index*2]);
        dfs(index*2);
        v.pop_back();
    }
}

int main(){
    int ismin=1,ismax=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    v.push_back(a[1]);
    dfs(1);
    for(int i=2;i<=n;i++){
        if(a[i]<a[i/2]) ismin=0;
        if(a[i]>a[i/2]) ismax=0;
    }
    if(ismin==1){
        printf("Min Heap");
    } else if(ismax==1){
        printf("Max Heap");
    } else {
        printf("Not Heap");
    }
    return 0;
}
