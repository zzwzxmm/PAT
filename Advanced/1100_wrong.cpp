#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
void transmars(string s,string m1[], string m2[]){
    int a=0;
    string tmp,tmp2;
    if (s.length()==4){
        cout << "0" << endl;
    } else if(s.length()==3) {
        tmp=s;
        for(int i=0;i<13;i++){
            if(tmp==m1[i]) {
                cout << i << endl;
                break;
            }
            if(tmp==m2[i]) {
                cout << i*13 << endl; 
                break;
            }
        }
    } else if(s.length()>4) {
        for(int i=0;i<=2;i++){
            tmp[i]=s[i];
        }   
        for(int i=4;i<s.length();i++){
            tmp2[i]=s[i];
        }
        for(int i=0;i<13;i++){
            if(tmp==m2[i]) {
                a+=i*13;
                break;
            }
        } 
        for(int i=0;i<13;i++){
            if(tmp2==m1[i]) {
                a+=i;
                break;
            }
        }
        cout << a << endl;
    }
    return;
}

void transearth(string s,string m1[],string m2[]){
    int a=0;
    for(int i=0;i<s.length();i++){
        a=a*10+s[i]-'0';
    }
    if(a==0) {
        cout << m1[0] << endl;
    }else if(a<13){
        cout << m1[a] << endl;
    } else {
        cout << m2[a/13];
        a%=13;
        if(a==0) cout <<endl;
        else cout << " " << m1[a] << endl;
    }
    return;
}

int main(){
    string m1[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string m2[13]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        char c;
        int j=0;
        getchar();
        while((c=getchar())!='\n') {
            scanf("%c",&s[j]);
            j++;
        }
        while(s[0]==' '){
            s.erase(s[0]);
        }
        if(s[0]<65){
            transmars(s,m1,m2);
        } else {
            transearth(s,m1,m2);
        }
    }
    return 0;
}
