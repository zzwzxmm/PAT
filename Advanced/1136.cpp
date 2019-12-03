#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int ispa(string s){
	int flag=1;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) {
			flag=0;
			break;
		}
	}	
	return flag;
}

string sreverse(string s){
	string sr=s;
	for(int i=0;i<s.size();i++){
		sr[i]=s[s.size()-1-i];
	}
	return sr;
}

string splus(string s1,string s2){
	string sum="";
	int jinwei=0,he;
	for(int i=s1.size()-1;i>=0;i--){
		he=(s1[i]-'0')+(s2[i]-'0')+jinwei;
		if(he>=10) {
			he%=10;
			jinwei=1;
		} else {
			jinwei=0;
		}
		sum+=he+'0';
	}
	if(jinwei) sum+=jinwei+'0';
	sum=sreverse(sum);
	return sum;
}

int main(){
	string s;
	cin >> s;
    if(s==sreverse(s)) cout << s << " is a palindromic number." << endl;
    else {
	    string sr,sum;
	    int i=10,flag=1;
	    while(i--){
	    	sr=sreverse(s);
	    	sum=splus(s,sr);
	    	cout << s << " " << "+" << " " << sr << " " << "=" << " " << sum << endl;
	    	if(ispa(sum)){
	    		cout << sum << " is a palindromic number." << endl;
	    		flag=0;
	    		break;
	    	} else {
	    		s=sum;
	    	}
	    }
	    if(flag){
	    	cout << "Not found in 10 iterations." << endl;
	    }
    }
	return 0;
}














