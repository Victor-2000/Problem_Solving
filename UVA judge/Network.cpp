//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251
#include <bits/stdc++.h>
#define NMAX 100000
using namespace std;

vector <int> A[NMAX];
string s;
bool isCV[NMAX];
int sol,d[NMAX],lo[NMAX],b,c;

void dfs(int node,int parent){
	int ch=0,k=d[parent]+1;
	d[node]=lo[node]=k;
	for(int i=0;i<A[node].size();i++){
		if(A[node][i]==parent)continue;
			if(!d[A[node][i]]){
				ch++;
				dfs(A[node][i],node);
				lo[node]=min(lo[A[node][i]],lo[node]);
				if(d[node]<=lo[A[node][i]] && (k!=1 || ch>1)){
					if(!isCV[node]){
						isCV[node]=1;
						sol++;
					}
				}
			}else lo[node]=min(d[A[node][i]],lo[node]);
		}
}

int main(){
	int n;
	cin>>n;
	while(n){
		for(int i=0;i<=n;i++){
			A[i].clear();
			isCV[i]=d[i]=lo[i]=0;
		}
		sol=0;
		getline(cin,s);
		while(s[0]!='0'){
			stringstream ss(s);
			ss>>b;
			for(int i=1;i<s.size();i++){
					ss>>c;
					A[c].push_back(b);
					A[b].push_back(c);
				}
			getline(cin,s);
		}
		dfs(1,0);
		cout<<sol<<'\n';
		cin>>n;
	}
	return 0;
}
