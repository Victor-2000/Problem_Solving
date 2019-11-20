//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498

#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

map <string,int> m;
int r[MAX],v[MAX],l=0;

int Find(int a){
	if(v[a]==a) return a;
	v[a]=Find(v[a]);
	return v[a];
}

bool isSameSet(int a,int b){
	return Find(a)==Find(b);
}

void Union(int a,int b){
	if(!isSameSet(a,b)){
		int x=Find(a),y=Find(b);
		if(r[x]>r[y]){
			v[y]=x;
		}else{
			v[x]=y;
			if(r[x]==r[y])r[y]++;
		}
	}
}

void MakeCell(string s){
	m[s]=l++;
}

void clear(){
	l=0;
	m.clear();
	for(int i=0;i<MAX;i++){
		r[i]=0;
		v[i]=i;
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		clear();
		int f;
		cin>>f;
		while(f--){
			string a,b;
			cin>>a>>b;
			if(m.find(a)==m.end())MakeCell(a);
			if(m.find(b)==m.end())MakeCell(b);
			Union(m[a],m[b]);
			int x=Find(m[a]),sol=0;
			for(int i=0;i<l;i++){
				if(Find(v[i])==x)sol++;
			}
			cout<<sol<<'\n';
		}
	}
	return 0;
}
