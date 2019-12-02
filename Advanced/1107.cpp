#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=1010;
int n;
vector<int> father,isroot;
int hob[MAX];

int findfather(int a){
    int x=a;
    while(father[x]!=x){
        x=father[x];
    }
    while(father[a]!=a){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}

void Union(int a,int b){
    int Fa=findfather(a);
    int Fb=findfather(b);
    if(Fa!=Fb){
        father[Fa]=Fb;
    }
}

int cmp(int a,int b){
    return a>b;
}

int main(){
    int n,k;
    scanf("%d",&n);
    father.resize(n+1);
    isroot.resize(n+1);
    for(int i=1;i<=n;i++) father[i]=i;
    fill(hob,hob+MAX,0);
    fill(isroot.begin(),isroot.end(),0);
    for(int i=1;i<=n;i++){
        scanf("%d:",&k);
        int h;
        for(int j=0;j<k;j++){
            scanf("%d",&h);
            if(hob[h]==0) {hob[h]=i;}
            Union(i,findfather(hob[h]));
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        isroot[findfather(i)]++;
    }
    for(int i=1;i<=n;i++){
        if(isroot[i]!=0) {
            cnt++;
        }
    }
    sort(isroot.begin(),isroot.end(),cmp);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d%c",isroot[i],(i==cnt-1)?'\n':' ');
    }
    return 0;
}
