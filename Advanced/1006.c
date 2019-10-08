#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct student{
    char id[30];
    int inh;
    int inm;
    int ins;
    int outh;
    int outm;
    int outs;
}student;

int cmpearly(const void* a,const void* b){
    student c = *(student*)a;
    student d = *(student*)b;
    if(c.inh!=d.inh) return c.inh-d.inh;
    else if(c.inm!=d.inm) return c.inm-d.inm;
    else return c.ins-d.ins;
}

int cmplate(const void* a,const void* b){
    student c = *(student*)a;
    student d = *(student*)b;
    if(c.outh!=d.outh) return d.outh-c.outh;
    else if(c.outm!=d.outm) return d.outm-c.outm;
    else return d.outs-c.outs;
}

int main(){
    int n;
    scanf("%d",&n);
    int i;
    student s[n];
    for(i=0;i<n;i++){
        scanf("%s %d:%d:%d %d:%d:%d",s[i].id,&s[i].inh,&s[i].inm,&s[i].ins,&s[i].outh,&s[i].outm,&s[i].outs);
    }
    qsort(s,n,sizeof(*s),cmpearly);
    printf("%s ",s[0].id);
    qsort(s,n,sizeof(*s),cmplate);
    printf("%s",s[0].id);
    return 0;
}
