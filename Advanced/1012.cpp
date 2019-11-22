#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAX=2010;
int exist[1000000],flag=-1;
struct stu{
    int id;
    int score[4];
    int rank[4];
};

int cmp(const void *a, const void *b){
    stu s1=*(stu*) a;
    stu s2=*(stu*) b;
    return s1.score[flag]<s2.score[flag]; // NOTE!!! < from large to small, > from small to large;
}

/*
bool cmp(stu a,stu b) {
    return a.score[flag]<b.score[flag];
}
*/

int main(){
    int n,m,id,c,M,e,a;
    scanf("%d%d",&n,&m);
    fill(exist,exist+1000000,0);
    stu s[n];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&id,&c,&M,&e);
        s[i].id=id;
        s[i].score[1]=c;
        s[i].score[2]=M;
        s[i].score[3]=e;
        a=(c+M+e)/3.0+0.5;
        s[i].score[0]=a;
    }
    for(int i=0;i<=3;i++){
        flag=i;
        qsort(s,n,sizeof(s[0]),cmp);
        s[0].rank[flag]=1;
        for(int j=1;j<n;j++){
            s[j].rank[flag]=j+1;
            if(s[j].score[flag]==s[j-1].score[flag]){
                s[j].rank[flag]=s[j-1].rank[flag];
            }
        }
    }
    for(int i=0;i<n;i++){  //NOTE!!!! after sort!!!
        exist[s[i].id]=i+1;
    }
    char cu[5]={'A','C','M','E'};
    for(int i=0;i<m;i++){
        int id;
        scanf("%d",&id);
        if(exist[id]){
            int rank=2020,type;
            for(int j=0;j<4;j++){
                if(s[exist[id]-1].rank[j]<rank){
                    rank=s[exist[id]-1].rank[j];
                    type=j;
                }
            }
            printf("%d %c\n",rank,cu[type]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}
