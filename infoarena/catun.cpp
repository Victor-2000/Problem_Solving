//Condition of the problem: https://www.infoarena.ro/problema/catun

#include <bits/stdc++.h>
#define NMAX 36010
#define pii pair<int,int>
#define vii vector<pii>
#define F first
#define S second
#define INF 0xfffffff
 
using namespace std;
 
int dist[NMAX],O[NMAX],n,m,k,L[NMAX];
bool iL[NMAX];
vii A[NMAX];
 
void Dijkstra(int s){
	priority_queue <pii,vector<pii>,greater <pii> > pq;
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty()){
		pii c;
		c.F=pq.top().S;
		c.S=pq.top().F;
		pq.pop();
		if(c.S>dist[c.F])continue;
		for(int i=0;i<A[c.F].size();i++){
			if(!iL[A[c.F][i].F]||A[c.F][i].F==s)
			if(A[c.F][i].S+dist[c.F]<dist[A[c.F][i].F]){
				dist[A[c.F][i].F]=A[c.F][i].S+c.S;
				O[A[c.F][i].F]=s;
				pq.push({dist[A[c.F][i].F],A[c.F][i].F});
			}else if(A[c.F][i].S+dist[c.F]==dist[A[c.F][i].F]){
				if(O[A[c.F][i].F]>s)O[A[c.F][i].F]=s;
				pq.push({dist[A[c.F][i].F],A[c.F][i].F});
			}
		}
	}
}
 
int main(){
	ifstream cin("catun.in");
	ofstream cout("catun.out");
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		cin>>L[i];
		iL[L[i]]=1;
	}
	for(int i=0;i<=n;i++){
		dist[i]=INF;
		O[i]=0;
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		A[a].push_back({b,c});
		A[b].push_back({a,c});
	}
	for(int i=0;i<k;i++)Dijkstra(L[i]);
	for(int i=0;i<k;i++)O[L[i]]=0;
	for(int i=1;i<=n;i++)cout<<O[i]<<' ';
}
