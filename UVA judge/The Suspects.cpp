//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638

#include <bits/stdc++.h>

using namespace std;

#define MAX 30010

int v[MAX],r[MAX];

void clear(){
	for (int i=0;i<MAX;i++){
		v[i]=i;
		r[i]=0;
	}
}

int Find(int a){
	if(v[a]==a) return a;
	v[a]=Find(v[a]);
	return v[a];
}

void Union(int a,int b){
	int x=Find(a),y=Find(b);
	if(x!=y){
		if(r[x]>r[y]){
			v[y]=x;
		}else{
			v[x]=y;
			if(r[x]==r[y]) r[y]++;
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	while(n || m){
		clear();
		while(m--){
			int k;
			cin>>k;
			for(int i=0;i<k;i++){
				int c,pr;
				cin>>c;
				if(i)Union(c,pr);
				pr=c;
			}
		}
		int x=Find(0),sol=0;
		for(int i=0;i<n;i++){
			if(Find(v[i])==x) sol++;
		}
		cout<<sol<<'\n';
		cin>>n>>m;
	}
	return 0;
}
