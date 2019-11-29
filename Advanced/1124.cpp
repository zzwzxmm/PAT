#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    map<string,int> list;
    vector<string> nlist;
    string nickname;
    for(int i=0;i<n;i++){
        cin >> nickname;
        nlist.push_back(nickname);
        list[nickname]=0;
    }
    if(s>n) printf("Keep going...");
    else{
        for(int i=s-1;i<n;){
            string test=nlist[i];
            if(list[test]==1) i++;
            else{
                cout << test << endl;
                i+=m;
                list[test]=1;
            }
        }
    }
    return 0;
}
