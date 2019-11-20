//Condition of the problem: https://www.infoarena.ro/problema/arbvalmax

#include <bits/stdc++.h>
#define NMAX 300010
#define ll long long
using namespace std;
 
/*Problema se rezolva prin programare dinamica
dp1[i]-valoarea maximala fara a socoti subarborele i inclusiv i,
dp2[i]-valoarea maximala fara a socoti lantul 1-->i si subarborele i inclusiv i */
 
ll G[NMAX],c,P[NMAX],dp1[NMAX],BS[NMAX][3],dp2[NMAX],d[NMAX],x,y;
int n,m;
vector <ll> A[NMAX];
 
void dfs(int node,int parent){
	int b1=0,b2=0;
	d[node]=G[node];
	for(int i=0;i<A[node].size();i++){
		int fiu=A[node][i];
		if(fiu!=parent){
			dfs(fiu,node);
			d[node]=max(d[node],d[fiu]);
			if(d[b1]<=d[fiu]){
				b2=b1;
				b1=fiu;
			}else if (d[b2]<=d[fiu]){
				b2=fiu;
			}
		}
	}
	BS[node][1]=b1;
	BS[node][2]=b2;
}
 
void dfsdp(int node,int parent){
	dp1[node]=max(dp1[P[node]],G[P[node]]);
	if(BS[P[node]][1]==node){
		dp1[node]=max(dp1[node],d[BS[P[node]][2]]);
	}else{
		dp1[node]=max(dp1[node],d[BS[P[node]][1]]);
	}
	dp2[node]=dp2[P[node]];
	if(BS[P[node]][1]==node){
		dp2[node]=max(dp2[node],d[BS[P[node]][2]]);
	}else{
		dp2[node]=max(dp2[node],d[BS[P[node]][1]]);
	}
	for(int i=0;i<A[node].size();i++){
		if(A[node][i]!=parent){
			dfsdp(A[node][i],node);
		}
	}
}
 
int main(){
	ifstream cin("arbvalmax.in");
	ofstream cout("arbvalmax.out");
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>c;
		P[i+1]=c;
		A[i+1].push_back(c);
		A[c].push_back(i+1);
	}
	for(int i=1;i<=n;i++){
		cin>>G[i];
		dp1[i]=dp2[i]=d[i]=BS[i][1]=BS[i][2]=0;
	}
	dfs(1,0);
	dfsdp(1,0);
	for(int i=0;i<m;i++){
		cin>>x>>y;
		cout<<max(d[BS[y][1]],max(dp1[x],dp2[y]))<<'\n';
	}
}
