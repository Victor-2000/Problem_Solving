//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int p[MAX],r[MAX];

void reset(int n){
	for(int i=0;i<=n;i++){
		p[i]=i;
		r[i]=0;
	}
}

int FindSet(int a){
	if(p[a]!=a)p[a]=FindSet(p[a]);
	return p[a];
}

bool SameSet(int a,int b){
	return FindSet(a)==FindSet(b);
}

void connect(int a, int b){
	if(!SameSet(a,b)){
		int x=FindSet(a),y=FindSet(b);
		if(r[x]>r[y]){
			p[y]=x;
		} else{
			p[x]=y;
			if(r[x]==r[y])r[y]++;
		} 
	}
}

int main(){
	int nc;
	cin>>nc;
	for(int i=0;i<nc;i++){
		int n,t=0,f=0;
		string s;
		cin>>n;
		reset(n);
		getline(cin,s);
		while(getline(cin,s) && (s[0]=='c'||s[0]=='q')){
			int a,b;
			char c;
			sscanf(s.c_str(),"%c %d %d",&c,&a,&b); //scanf la string (sscanf se efectueaza)  la s din sscanf adaugam .c_str()!!!
			if(c=='c'){
				connect(a,b);
			}else if(c=='q'){
				if(SameSet(a,b))t++;
				else f++;
			}
		}
		if(i) cout<<'\n';
		printf("%d,%d\n",t,f);
	}
	
	return 0;
}
