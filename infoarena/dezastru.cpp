//Condition of the problem: https://www.infoarena.ro/problema/dezastru

#include <bits/stdc++.h>
 
using namespace std;
 
#define NMAX 26
 
ifstream fin("dezastru.in");
 
double s;
int n,km,S[NMAX],F[NMAX];
double P[NMAX],V[NMAX],PD[NMAX][NMAX],N[NMAX][NMAX];
 
void dp(){
	for(int i=0;i<=n;i++) PD[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=km;j++){
			PD[i][j]=PD[i-1][j]+PD[i-1][j-1]*P[i];
 
		}
	}
for(int j=1;j<=km;j++){
	for(int i=1;i<=n;i++){
			N[i][j]=N[i-1][j]+N[i-1][j-1];
			//cerr<<N[i][j]<<'-'<<N[i-1][j]<<'-'<<N[i-1][j-1]<<' ';
		}
		//cerr<<'\n';
	}
}
 
 
int main(){
	freopen ("dezastru.out","w",stdout);
	V[0]=1;
	fin>>n>>km;
	for(int i=0;i<=n;i++)
		N[i][0]=1;
	for(int i=1;i<=n;i++){ 
		fin>>P[i];
	}
	dp();
	s = PD[n][km]/N[n][km];
	printf("%.6f",s);
	//cerr<<clock()*1000.0/CLOCKS_PER_SEC<<'\n';
	return 0;
}
