//Condition of the problem: https://www.infoarena.ro/problema/sobo
#include<bits/stdc++.h>
#define CMAX 1<<16
#define INF 12000000000
using namespace std;
 
long long dp[CMAX],V[1010],C[2][CMAX],n,l;
string A[15];
int main(){
	ifstream cin("sobo.in");
	ofstream cout("sobo.out");
	cin>>n>>l;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<l;i++)cin>>V[i];
	int x=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){
			C[A[i][j]-'0'][j]|=x;
		}
		x*=2;
	}
	for(int p=1;p<x;p++){
		dp[p]=INF;
	}
	for(int i=1;i<x;i<<=1){
		dp[i]=0;
	}
	for(int p=1;p<x;p++){
		for(int i=0;i<l;i++){
			int s1=p&C[0][i],s2=p&C[1][i];
			dp[p]=min(dp[p],V[i]+max(dp[s1],dp[s2]));
		}
	}
	cout<<dp[x-1];
	return 0;
}

