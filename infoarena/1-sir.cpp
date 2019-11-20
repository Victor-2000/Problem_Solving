//Condition of the problem: https://www.infoarena.ro/problema/1-sir

#include <bits/stdc++.h>
#define MOD 194767
using namespace std;
 
int DP[2][33000],n,s;
 
ifstream fin("1-sir.in");
ofstream fout("1-sir.out");
 
int main(){
	fin>>n>>s;
	memset(DP[1],0,2);
	DP[1][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=i*(i-1)/2;j++)DP[i%2][j]=(DP[(i+1)%2][abs(j-(i-1))]+DP[(i+1)%2][j+i-1])%MOD;
	fout<<DP[n%2][s];
	return 0;
}
