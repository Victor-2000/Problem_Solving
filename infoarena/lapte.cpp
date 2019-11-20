//Condition of the problem: https://www.infoarena.ro/problema/lapte
#include <bits/stdc++.h>
using namespace std;
 
int N,L,m,dp[110][110],a[110],b[110],T[110][110];
 
ifstream fin("lapte.in");
ofstream fout("lapte.out");
 
bool f(int t){
	bool ist=false;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<=min(L,t/a[0]);i++){
		dp[0][i]=(t-a[0]*i)/b[0];
		T[0][i]=i;
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<=min(L,t/a[i]);j++){
			for(int k=0;k<=(L-j);k++){
				if(dp[i-1][k]!=-1 && dp[i-1][k]+(t-a[i]*j)/b[i]>dp[i][k+j]){
					dp[i][k+j]=dp[i-1][k]+(t-a[i]*j)/b[i];
					T[i][k+j]=j;
					if(k+j==L && dp[i][k+j]>=L){
						ist=true;
					}
				}
			}
		}
	}
	return ist;
}
 
void bk(int n,int l){
	if(n<0)return;
	bk(n-1,l-T[n][l]);
	fout<<T[n][l]<<' '<<(m-T[n][l]*a[n])/b[n]<<'\n';
}
 
int main(){
	fin>>N>>L;
	for(int i=0;i<N;i++){
		fin>>a[i]>>b[i];
	}
	int l=0,r=10000;
	m=(l+r)/2;
	while(l<=r){
		if(f(m))r=m-1;
		else l=m+1;
		m=(l+r)/2;
	}
	m=l;
	fout<<m<<'\n';
	bk(N-1,L);
	return 0;
}
