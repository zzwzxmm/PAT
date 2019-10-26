#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int add;
    int key;
    int nex;
    int isin;
}node;

int cmp(const void* a, const void* b){
    node c= *(node*)a;
    node d= *(node*)b;
    if(c.isin==0 || d.isin==0) return c.isin<d.isin;
    else  return c.key>d.key;
}

int main(){
    int i,m,head,add,key,nex,cnt=0;
    scanf("%d%d",&m,&head);
    node n[100000];
    for(i=0;i<100000;i++) { 
        n[i].isin=0;
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&add,&key,&nex);
        n[add].add=add;
        n[add].key=key;
        n[add].nex=nex;
    }
    for(i=head;i!=-1;i=n[i].nex){
        n[i].isin=1;
        cnt++;
    }
    qsort(n,100000,sizeof(n[0]),cmp);
    if(cnt!=0){
        printf("%d %05d\n",cnt,n[0].add);
        for(i=0;i<cnt;i++){
            if(i!=cnt-1) printf("%05d %d %05d\n",n[i].add,n[i].key,n[i+1].add);
            else printf("%05d %d %d\n",n[i].add,n[i].key,-1);
        }
    } else {
        printf("0 -1");
    }
    return 0;
}
