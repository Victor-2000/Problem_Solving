//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873

#include <bits/stdc++.h>

using namespace std;

int V[50010],A[50010],m,posm;
bool isV[50010];

int DFS(int node){
	isV[node]=1;
	if(!isV[A[node]] && A[node]!=-1){
		V[node]=DFS(A[node])+1;
	}
	if(isV[A[node]])V[node]=1;
	isV[node]=0;
	return V[node];
}

int T,u,v,n;

int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1; j<=n; j++){
			isV[j]=V[j]=0;
			A[j]=-1;
		}
		m=posm=0;
		for(int j=0;j<n;j++){
			cin>>u>>v;
			A[u]=v;
		}
		for(int j=1;j<=n;j++){
			if(!V[j])DFS(j);
			if(m<V[j]){
				m=V[j];
				posm=j;
			}
		}
	 cout<<"Case "<<i<<": "<<posm<<'\n';
	}
	return 0;
}
