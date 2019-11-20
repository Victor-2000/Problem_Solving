//Condition of the problem: https://www.infoarena.ro/problema/asmax

# include<bits/stdc++.h>
 
using namespace std;
 
vector <int> v[20000];
int dp[20000],n,sol=-1001;
char viz[20000];

void dfs(int p)
{	
	if(viz[p]) return; 
	viz[p]=1;
	int s = v[p].size();
	for(int f=0;f<s;f++){
	 dfs(v[p][f]);
	 if(viz[v[p][f]]==2)
	 dp[p]=max(dp[p],dp[v[p][f]]+dp[p]);
	}
	sol=max(sol,dp[p]);
	viz[p]=2;
}
 
int main(){
	ifstream fin("asmax.in");
	ofstream fout("asmax.out");
	fin>>n;
	memset(viz,0,n);
	for(int i=1;i<=n;i++)
		fin>>dp[i];
	int a,b;
	for(int i=1;i<n;i++){
		fin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int x = rand()%n+1;
	dfs(x);
	fout<<sol;
	return 0;
}
