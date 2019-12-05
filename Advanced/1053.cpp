#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=1010;
int n,m,s,cnt=0;
struct node{
	int id;
	int w;
	vector<int> v;
}data[MAX];
vector<int> tmp;
vector<int> ans[MAX];

int cmp(vector<int> a,vector<int> b){
	return a>b;
}

void dfs(int root,int weight){
	if(data[root].w+weight==s && data[root].v.size()==0){
		tmp.push_back(data[root].w);
		ans[cnt]=tmp;
		cnt++;
		tmp.pop_back(); 
	}
	else if(weight+data[root].w>s || (data[root].w+weight<s && data[root].v.size()==0)) return;
	else{
		tmp.push_back(data[root].w);
		for(int i=0;i<data[root].v.size();i++){
			dfs(data[root].v[i],weight+data[root].w);
		}
		tmp.pop_back();
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i].w);
		data[i].v.clear();
	}
	int fid,k,kid;
	for(int i=0;i<m;i++){
		scanf("%d%d",&fid,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&kid);
			data[fid].v.push_back(kid);
		}
	}
	dfs(0,0);
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<ans[i].size();j++){
			printf("%d%c",ans[i][j],(j==ans[i].size()-1)?'\n':' ');
		}
	}
	return 0;
}
