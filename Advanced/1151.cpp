#include <iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
const int MAX=10010;
int m,n;
int in[MAX],pre[MAX],cnt=1;
map<int,int> isin;

int main() {
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&in[i]);
	    isin[in[i]]=cnt;
	    cnt++;
	}
	for(int i=0;i<n;i++){
	    scanf("%d",&pre[i]);
	}
	int a,b;
	for(int i=0;i<m;i++){
	    scanf("%d%d",&a,&b);
	    if(!isin[a] && !isin[b]) printf("ERROR: %d and %d are not found.\n",a,b);
	    else if(!isin[a]) printf("ERROR: %d is not found.\n",a);
	    else if(!isin[b]) printf("ERROR: %d is not found.\n",b);
	    else {
	        for(int j=0;j<n;j++){
	            int k=pre[j];
                if(isin[k]>isin[a] && isin[k]>isin[b]){
	                continue;
	            }
	            if((isin[k]<isin[a] && isin[k]>isin[b]) || (isin[k]>isin[a] && isin[k]<isin[b])){
	                printf("LCA of %d and %d is %d.\n",a,b,k);
	                break;
	            } else if(k==a) {
	                printf("%d is an ancestor of %d.\n",a,b);
	                break;
	            } else if(k==b) {
	                printf("%d is an ancestor of %d.\n",b,a);
	                break;
	            }
	        }
	    }
	}
	return 0;
}
