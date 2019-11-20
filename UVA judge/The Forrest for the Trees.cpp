//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=540

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int ac=0,tr=0;
bool v[30];
vi l[30];

void dfs(int k,int c){
	if(v[c]) return;
	v[c]=1;
	if(l[c].size()){
		for(int i=0;i<l[c].size();i++){
			dfs(k+1,l[c][i]);	
		}
		if(!k)
		tr++;
	}else ac++;
}

void clr(){
	for (int i=0;i<30;i++){
		v[i]=0;
		l[i].clear();
	}
}

int c(char ch)
{
	return (ch-'A');
}

int main (){
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	for(int i=0;i<n;i++){
		char c1,c2;
		ac=tr=0;
		getline(cin,s);
		while(s[0]!='*'){
			l[c(s[1])].push_back(c(s[3]));
			l[c(s[3])].push_back(c(s[1]));
			getline(cin,s);
		}
		getline(cin,s);
		for(int j=0;j<s.size();j++){
			if(s[j]>='A' && s[j]<='Z')dfs(0,c(s[j]));
		}
		clr();
		printf("There are %d tree(s) and %d acorn(s).\n",tr,ac);
	}
	return 0;
}
