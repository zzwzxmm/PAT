#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        string a="";
        string b="";
        for(int j=0;j<s.size()/2;j++) a+=s[j];
        for(int j=s.size()/2;j<s.size();j++) b+=s[j];
        int m1=stoi(a);
        int m2=stoi(b);
        int m=m1*m2;
        int o=stoi(s);
        if(m==0) printf("No\n");
        else if(o%m==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
