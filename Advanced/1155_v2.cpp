#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int MAX=1010;
int n;
struct node{
    int data;
    int lc,rc;
}data[MAX];
vector<int> v;

void dfs(int root){
    v.push_back(data[root].data);
    if(root*2>n && root*2+1>n){
        for(int i=0;i<v.size();i++){
            printf("%d%c",v[i],(i==v.size()-1)?'\n':' ');
        }
        return;
    }
    if(data[root].rc!=-1) {
        dfs(data[root].rc);
        v.pop_back();
    }
    if(data[root].lc!=-1) {
        dfs(data[root].lc);
        v.pop_back();
    }
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf("%d",&data[i].data);
	    if(i*2<=n) data[i].lc=i*2;
	    else data[i].lc=-1;
	    if(i*2+1<=n) data[i].rc=i*2+1;
	    else data[i].rc=-1;
	}
	dfs(1);
	int ismax=1,ismin=1;
	for(int i=2;i<=n;i++){
	    if(data[i].data>data[i/2].data) ismax=0;
	    if(data[i].data<data[i/2].data) ismin=0;
	}
	if(ismax) printf("Max Heap\n");
	else if(ismin) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
