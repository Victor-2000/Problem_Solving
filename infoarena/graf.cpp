//Condition of the problem: https://www.infoarena.ro/problema/graf

#include <bits/stdc++.h>
#define MAXN 7510
using namespace std;
 
int V[MAXN],V2[MAXN];
vector <int> A[MAXN],S[MAXN];
 
void BFS1(int x,int y){
	queue <int> q;
	q.push(x);
	V[x]=1;
	while(!q.empty() && q.front()!=y){
		int c=q.front();
		for(int i=0;i<A[c].size();i++){
			if(!V[A[c][i]]){
				q.push(A[c][i]);
				V[A[c][i]]=V[c]+1;
			}
		}
		q.pop();
	}
}
 
void BFS2(int x,int y){
	queue <int> q;
	q.push(x);
	V2[x]=1;
	S[1].push_back(x);
	while(!q.empty() && q.front()!=y){
		int c=q.front(),ind,nc=0;
		for(int i=0;i<A[c].size();i++){
			if(V[A[c][i]]==V[x]-V2[c] && !V2[A[c][i]]){
				q.push(A[c][i]);
				V2[A[c][i]]=V2[c]+1;
				S[V2[A[c][i]]].push_back(A[c][i]);
				ind=A[c][i];
			}
		}
		q.pop(); 
	}
}
 
int main(){
	ifstream cin("graf.in");
	ofstream cout("graf.out");
	int x,y,n,m,a,b;
	cin>>n>>m>>x>>y;
	for(int i=0;i<n;i++)V2[i]=V[i]=0;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	BFS1(y,x);
	BFS2(x,y);
	vector <int> s;
	for(int i=0;i<=V[x];i++){
		if(S[i].size()==1)s.push_back(S[i][0]);
	}
	sort(s.begin(),s.end());
	cout<<s.size()<<'\n';
	for(int i=0;i<s.size();i++)cout<<s[i]<<' ';
	return 0;
}
