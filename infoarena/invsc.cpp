//Condition of the problem: https://www.infoarena.ro/problema/invsc

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("invsc.in");
ofstream fout("invsc.out");
 
#define NMAX 200100
 
int n,S[NMAX],N[NMAX],A[NMAX];
 
int main(){
	fin>>n;
	N[0]=0;
	for(int i=1;i<=n;i++){ 
		fin>>A[i]; 
		N[A[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(N[i]) N[i]+=N[i-1];
	}
	for(int i=1;i<=n;i++){
		S[i]=N[A[i]];
		N[A[i]]--;
	}
	for(int i=1;i<=n;i++) fout<<S[i]<<'\n';
	return 0;
}
