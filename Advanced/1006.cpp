#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
const int MAX=100010;
struct node{
    int id;
    int level;
    vector<int> child;
};
node data[MAX];
int n,mlevel=MAX;
double price,rate;
vector<int> list;

void levelorder(int r){
    queue<node> q;
    node root=data[r];
    root.level=0;
    q.push(root);
    while(!q.empty()){
        node top=q.front();
        q.pop();
        if(top.level<mlevel && top.child.size()==0){
            mlevel=top.level;
            list.clear();
            list.push_back(top.id);
        } else if(top.level==mlevel && top.child.size()==0){
            list.push_back(top.id);
        }
        if(top.child.size()!=0){
            for(int i=0;i<top.child.size();i++){
                int kid=top.child[i];
                data[kid].level=top.level+1;
                q.push(data[kid]);
            }
        }
    }
}

int main(){
    scanf("%d%lf%lf",&n,&price,&rate);
    rate=1.00+rate/100.00;
    int k,kid;
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        data[i].id=i;
        for(int j=0;j<k;j++){
            scanf("%d",&kid);
            data[i].child.push_back(kid);
        }
    }
    levelorder(0);
    double mprice=price*pow(rate,mlevel);
    printf("%.4lf %d",mprice,list.size());
    return 0;
}
