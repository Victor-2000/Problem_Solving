//Condition of the problem: https://www.infoarena.ro/problema/plimbare

#include <bits/stdc++.h>
#define NMAX 110
using namespace std;
 
int id[NMAX],idc=0,low[NMAX],m,n;
bool E[NMAX][NMAX],V[NMAX],in_stack[NMAX],stop=false;
vector<int> C,MC,S,A[NMAX];
 
void DFS(int u){
	id[u]=low[u]=++idc;
	S.push_back(u);
	in_stack[u]=1;
	
	for(int i=0;i<A[u].size();i++){
		int v=A[u][i];
		if(!id[v])DFS(v);
		if(in_stack[v])low[u]=min(low[u],low[v]);
	}
	
	if(low[u]==id[u]){
		C.clear();
		while(1){
			int c=S.back();
			S.pop_back();
			C.push_back(c);
			in_stack[c]=0;
			if(c==u)break;
		}
		if(C.size()>MC.size()) MC=C;
	}
}
 
int main(){
	ifstream cin("plimbare.in");
	ofstream cout("plimbare.out");
	cin>>n;
	m=n*(n-1)/2;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		A[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!id[i])DFS(i);
	}
	cout<<MC.size()<<'\n';
	for(int i=0;i<MC.size();i++){
		for(int j=0;j<A[MC[i]].size();j++)E[MC[i]][A[MC[i]][j]]=1;
	}
	bool ok=true;
	int l=MC.size();
	while(ok){
		ok=false;
		for(int i=0;i<l-1;i++){
			if(!E[MC[i]][MC[i+1]]){
				ok=true;
				swap(MC[i],MC[i+1]);
			}
		}
		if(!E[MC[l-1]][MC[0]]){
			swap(MC[0],MC[l-1]);
			ok=true;
		}
	}
	for(int i=0;i<l;i++)cout<<MC[i]<<' ';
	return 0;
}
