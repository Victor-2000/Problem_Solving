//Condition of the problem: https://www.infoarena.ro/problema/retele

#include <bits/stdc++.h>
#define NMAX 50010
#define vi vector <int>
using namespace std;
 
vector <int> S,A[NMAX];
vector <vi> CTC;
int n,m,idc=1,id[NMAX],low[NMAX];
bool in_stack[NMAX];
 
void DFS(int u){
	in_stack[u]=1;
	S.push_back(u);
	id[u]=low[u]=idc++;
	for(int i=0;i<A[u].size();i++){
		int v=A[u][i];
		if(!id[v]) DFS(v);
		if(in_stack[v])low[u]=min(low[u],low[v]);
	}
	if(id[u]==low[u]){
		vi C;
		C.clear();
		while(1){
			int c=S.back();
			S.pop_back();
			in_stack[c]=0;
			C.push_back(c);
			if(u==c) break;
		}
		CTC.push_back(C);
	}
}
 
int main(){
	ifstream cin("retele.in");
	ofstream cout("retele.out");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		A[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!id[i])DFS(i);
	}
	cout<<CTC.size()<<'\n';
	for(int i=0;i<CTC.size();i++){
		sort(CTC[i].begin(),CTC[i].end());
	}
	sort(CTC.begin(),CTC.end());
	for(int i=0;i<CTC.size();i++){
		cout<<CTC[i].size()<<' ';
		for(int j=0;j<CTC[i].size();j++){
			cout<<CTC[i][j]<<' ';
		}
		cout<<'\n';
	}
}

