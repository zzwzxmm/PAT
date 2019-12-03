#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX=10010,INF=1000000000;
vector<int> v[MAX];

int main(){
    int n,m,k,l,v1,v2;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&v1,&v2);
        v[v1].push_back(i);
        v[v2].push_back(i);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int ingraph[m]={false};
        scanf("%d",&l);
        for(int j=0;j<l;j++){
            int ver;
            scanf("%d",&ver);
            for(int l=0;l<v[ver].size();l++){
                ingraph[v[ver][l]]=true;
            }
        }
        int flag=1;
        for(int j=0;j<m;j++){
            if(ingraph[j]==false) {
                flag=0;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
