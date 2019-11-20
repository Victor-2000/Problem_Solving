//Condition of the problem: https://www.infoarena.ro/problema/ture

#include <bits/stdc++.h>
#define ll long long
#define BMAX 32800
#define NMAX 255
using namespace std;
 
ll n,m,k,ne,dp[2][BMAX];
bool sw=0,A[NMAX][NMAX];
 
ll c(ll x){
	ll t=0;
	for(ll i=1;i<=x;i<<=1){
		if(x&i)t++;
	}
	return t;
}
 
int main(){
	ifstream cin("ture.in");
	ofstream cout("ture.out");
	cin>>n>>m>>k;
	cin>>ne;
	if(m>n){
		swap(m,n);
		sw=1;	
	}
	memset(A,0,sizeof A);
	memset(dp,0,sizeof dp);
	for(int i=0;i<ne;i++){
		ll a,b;
		cin>>a>>b;
		if(sw)swap(a,b);
		a--;b--;
		A[a][b]=1;
	}
	dp[0][0]=dp[1][0]=1;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<(1<<m);j++)
      {
          for(int k=0;k<m;k++)
          {
              if(!(j&(1<<k)))
              {
                  if(A[i][k]==0)
                  dp[1][j+(1<<k)]+=dp[0][j];
              }
          }
      }
      for(int j=0;j<(1<<m);j++)
        dp[0][j]=dp[1][j];
  }
	ll s=0;
	for(ll i=0;i<(1ll<<m);i++){
		if(c(i)==k){
			s+=dp[1][i];
		}
	}
	cout<<s;
}
