//Condition of the problem: https://www.infoarena.ro/problema/distante

#include <bits/stdc++.h>
#define pii pair<int,int>
#define vii vector<pii>
#define F first
#define S second
#define NMAX 50010
#define INF 0xfffffff
using namespace std;
 
int dist[NMAX],t,n,a,b,c,m,D[NMAX],s;
vii A[NMAX];
 
void clear(){
	for(int i=0;i<=n;i++){
		dist[i]=INF;
		A[i].clear();
	}
}
 
void Dijkstra(int s){
	priority_queue <pii,vector<pii>,greater<pii> > pq;
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty()){
		pii c;
		c.F=pq.top().S;
		c.S=pq.top().F;
		pq.pop();
		if(c.S>dist[c.F])continue;
		for(int i=0;i<A[c.F].size();i++){
			if(c.S+A[c.F][i].S<dist[A[c.F][i].F]){
				dist[A[c.F][i].F]=c.S+A[c.F][i].S;
				pq.push({c.S+A[c.F][i].S,A[c.F][i].F});
			}
		}
	} 
}
 
int main(){
	ifstream cin("distante.in");
	ofstream cout("distante.out");
	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		for(int i=1;i<=n;i++)cin>>D[i];
		clear();
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			A[a].push_back({b,c});
			A[b].push_back({a,c});
		}
		Dijkstra(s);
		int i;
		for(i=1;i<=n;i++){
			if(D[i]!=dist[i])break;
		}
		if(i!=n+1)cout<<"NU\n";
		else cout<<"DA\n";
	}
	return 0;
}
