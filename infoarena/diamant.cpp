//Condition of the problem: https://www.infoarena.ro/problema/diamant

#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 10000
 
int DP[2][160010],n,m,x,ne=1;
long long mx;
 
ifstream fin("diamant.in");
ofstream fout("diamant.out");
 
int main(){
	fin>>n>>m>>x;
	memset(DP,0,sizeof DP);
	DP[0][0]=DP[0][1]=mx=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1 && j==1) continue;
			mx+=i*j;
			for(int k=0;k<=mx;k++){
				DP[ne%2][k]=((DP[(ne+1)%2][k+i*j]+DP[(ne+1)%2][abs(k-i*j)])%MOD+DP[(ne+1)%2][k])%MOD;	
			}
			ne++;
		}
	}
	x=abs(x);
	if(x>160000)fout<<0;
	else fout<<DP[(ne+1)%2][x]%MOD;
	return 0;
}
