//Condition of the problem: https://www.infoarena.ro/problema/easygraph

#include <bits/stdc++.h>
#define MAXN 15010
#define ll long long
 
using namespace std;
vector <int> AT[MAXN];
bool V[MAXN];
int n,m,t,a,b,Val[MAXN];
ll DP[MAXN],s;
 
void topSort(int node){
	V[node]=1;
	DP[node]=Val[node];
	for(int i=0;i<AT[node].size();i++){
		if(!V[AT[node][i]]){
			topSort(AT[node][i]);
		}
		DP[node]=max(DP[AT[node][i]]+Val[node],DP[node]);
	}
}
 
int main(){
	ifstream cin("easygraph.in");
	ofstream cout("easygraph.out");
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>Val[i];
			V[i]=0;
			AT[i].clear();
		}
		for(int i=0;i<m;i++){
			cin>>a>>b;
			AT[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		if(!V[i])topSort(i);
		s=DP[1];
		for(int i=2;i<=n;i++)s=max(DP[i],s);
		cout<<s<<'\n';
	}
	return 0;
}
