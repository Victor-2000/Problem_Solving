//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1886

#include <bits/stdc++.h>

using namespace std;

string av=" .,!?\n",s;

void change(){
	for(int i=0;i<s.size();i++)
		for(int j=0;j<5;j++){
				if(s[i]==av[j]){
					s.erase(i,1);
					i--;
				}else s[i]=toupper(s[i]); 
		}
}

bool isPal(string s){
	int l=s.size(),m=l/2+l%2;
	for(int i=0;i<m;i++)
		if(s[i]!=s[l-i-1]) return false;
	return true;
}

int main(){
	getline(cin,s);
	change();
	int o=0;
	while(s!="DONE"){
		if(isPal(s))cout<<"You won't be eaten!\n";
		else cout<<"Uh oh..\n";
		getline(cin,s);
		change();
	}
	return 0;
}
