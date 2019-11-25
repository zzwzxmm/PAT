#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
string m1[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string m2[13]={"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    
void transmars(string s){
    string sm = s.substr(0,3),sm2;
    int t1=0,t2=0;
    if(s.length()>4) sm2=s.substr(4,3);
    for(int i=1;i<13;i++){
        if(sm == m1[i] || sm2==m1[i]) t2=i;
        if(sm == m2[i]) t1=i;
    }
    cout << t1*13+t2 << endl;
    return;
}

void transearth(int a){
    if(a<13) cout << m1[a] << endl;
    else if(a%13 !=0) cout << m2[a/13] << " " << m1[a%13] << endl;
    else cout << m2[a/13] << endl;
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        string s;    
        getline(cin,s);
        if(s[0]<'a'){
            transearth(stoi(s));
        } else {
            transmars(s);
        }
    }
    return 0;
}
