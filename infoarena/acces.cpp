//Condition of the problem: https://www.infoarena.ro/problema/acces

#include <bits/stdc++.h>
 
using namespace std;
 
bool T[1010][1010];
int m,n,k,dp[1010][1010];
int main(){
	ifstream cin("acces.in");
	ofstream cout("acces.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>T[i][j];
			if(T[i][j]){
				if(i==1 || j==1)dp[i][j]=0;
				else if(T[i][j-1])dp[i][j]=dp[i][j-1];
				else if(T[i-1][j])dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i-1][j-1];
			}else{
				int s=0;
				if(i>1 && !T[i-1][j]){
					s+=dp[i-1][j];
				}
				if(j>1 && !T[i][j-1]){
					if(s){
						s-=dp[i-1][j-1];
					}
					s+=dp[i][j-1];	
				}
				dp[i][j]=s+1;
			}
		}
	}
	cin>>k;
	while(k--){
		int y,x;
		cin>>y>>x;
		cout<<dp[y][x]<<'\n';
	}
	return 0;
}

