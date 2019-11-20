//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2502

#include <bits/stdc++.h>

using namespace std;

string sc="+x";

string intoarce(string s){
	string sol;
	if(s=="No"){
		return sc;
	}
	if(sc[1]=='x'){
		if(sc[0]=='-'){
			if(s[0]=='+'){
				sol+='-';
			} else sol+='+';
			sol+=s[1];
			return sol;
		}else return s;
	} else if(sc[1]==s[1]){
		if(s==sc){
			return "-x";
		} else return "+x";
	}else return sc; 
}

int main (){
	int n;
	scanf("%d",&n);
	while(n){
		string s;
		for(int i=0;i<n-1;i++){	
			cin>>s;
			sc=intoarce(s);
		}
		cout<<sc<<'\n';
		sc="+x";
		scanf("%d",&n);
	}
	return 0;
}
