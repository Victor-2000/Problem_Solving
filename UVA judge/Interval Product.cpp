//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3977

#include <bits/stdc++.h>

using namespace std;

#define ub(n) n&(-n)
#define MAX 100010

int ftn[MAX],ftz[MAX],v[MAX],n,k;

void clear(int n){
	for(int i=0;i<=n;i++)v[i]=ftn[i]=ftz[i]=0;
}
//1-pos;-1-nega;0-zero
void build(int n){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=ub(j)){
			if(v[i]==-1){
				ftn[j]++;
			}else if(!v[i]){
				ftz[j]++;
			}
		}
	}
}
void update(int pos,int val,int n){
	int prec=v[pos];
	v[pos]=val;
	for(int i=pos;i<=n;i+=ub(i)){
		if(val==-1){
			ftn[i]++;
		}else if(!val){
			ftz[i]++;
		}
		if(prec==-1){
			ftn[i]--;
		}else if(!prec){
			ftz[i]--;
		}
	}
}

pair <int,int> search(int a){
	int valz=0,valn=0;
	for(;a;a-=ub(a)){
		valz+=ftz[a];
		valn+=ftn[a];
	}
	pair <int,int> p;
	p.first=valz;
	p.second=valn;
	return p;
}

pair <int,int> query(int I,int J){
	pair <int,int> a,b,s;
	if(I==1){
		a.first=0;
		a.second=0;
	} else a=search(I-1);
	b=search(J);
	s.first=b.first-a.first;
	s.second=b.second-a.second;
	return s;
}

void write(int n){
	for(int i=1;i<=n;i++){
			cout<<ftz[i]<<' ';
		}cout<<'\n';
		for(int i=1;i<=n;i++){
			cout<<ftn[i]<<' ';
		}cout<<'\n';
}

int main(){
	int n,k;
	while(cin>>n>>k){
		clear(n);
		for(int i=1;i<=n;i++){
			int val;
			cin>>val;
			if(val<0)v[i]=-1;
			else if(val>0)v[i]=1;
			else v[i]=0;
		}
		build(n);
		char c;
		int a,b;
		for(int i=1;i<=k;i++){
			cin>>c>>a>>b;
			if(c=='C'){
				if(b>0)b=1;
				else if(b<0)b=-1;
				else b=0;
				update(a,b,n);
			}else{
			 	pair <int,int> sol;
			 	sol=query(a,b);
			 	if(sol.first) cout<<0;
			 	else if(sol.second % 2 == 0) cout<<'+';
			 	else cout<<'-';
			}	
		}
	cout<<'\n';
	}
	return 0;
}
