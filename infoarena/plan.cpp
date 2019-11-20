//Condition of the problem: https://www.infoarena.ro/problema/plan

#include <bits/stdc++.h>
#define vi vector <int>
#define NMAX 260
 
using namespace std;
 
int m,n,idc=1,id[NMAX],AC[NMAX],low[NMAX],in[NMAX],out[NMAX];
bool in_stack[NMAX];
vi S,A[NMAX];
vector <vi> CTC;
 
void DFS(int u){
	S.push_back(u);
	in_stack[u]=1;
	id[u]=low[u]=idc++;
	
	for(int i=0;i<A[u].size();i++){
		int v=A[u][i];
		if(!id[v])DFS(v);
		if(in_stack[v])low[u]=min(low[v],low[u]);
	}
	
	if(low[u]==id[u]){
		vi C;
		while(1){
			int c=S.back();
			S.pop_back();
			in_stack[c]=0;
			AC[c]=CTC.size();
			C.push_back(c);
			if(u==c) break;
		}
		CTC.push_back(C);
	}
}
 
int main(){
	ifstream cin("plan.in");
	ofstream cout("plan.out");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		A[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!id[i])DFS(i);
	}
	for(int i=1;i<=n;i++){
		for(int k=0;k<A[i].size();k++){
			int u=AC[i],v=AC[A[i][k]];
			if(u!=v){
				in[v]++;
				out[u]++;
			}
		}
	}
	vi outs,ins;
	int inc=0,oc=0;
	for(int i=0;i<CTC.size();i++){
		if(!in[i]){
			ins.push_back(i);
			inc++;
		}
		if(!out[i]){
			outs.push_back(i);
			oc++;
		}
	}
	int l=max(inc,oc);
	if(l<=1)cout<<0<<'\n';
	else{
		cout<<l<<'\n';
		for(int i=0;i<l;i++){
			int m=min(inc-1,i),M=max(oc-i-1,0);
			cout<<CTC[outs[M]][0]<<' '<<CTC[ins[m]][0]<<'\n';
		}	
	}
	return 0;
}
