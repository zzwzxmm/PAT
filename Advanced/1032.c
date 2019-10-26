#include<stdio.h>
typedef struct Node{
    char data;
    int next;
    int flag;
}node;

int main(){
    int s1,s2,m;
    scanf("%d%d%d",&s1,&s2,&m);
    int i;
    node n[100000];
    int add,s,cnt=0;
    for(i=0;i<m;i++){
        scanf("%d",&add);
        scanf(" %c %d",&n[add].data,&n[add].next);
        n[add].flag=0;
    }
    int cnt2=0;
    while(s1!=-1){
        n[s1].flag=1;
        s1=n[s1].next;
    }
    while(s2!=-1){
        if(n[s2].flag==1) {
            break;
        }
        s2=n[s2].next;
    }
    if(s2!=-1) printf("%05d",s2);
    else printf("-1");
    return 0;
}
