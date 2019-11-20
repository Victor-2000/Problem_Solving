//Condition of the problem: https://www.infoarena.ro/problema/cuvinte

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");
 
int A[3][201],Nr[201],l=1,kc=1,k,S[201],n,ind=0;
 
int main(){
	fin>>n>>k;
	for(int i=0;i<=n;i++){
		if(i)fin>>A[0][i];
		Nr[i]=1;
		A[1][i]=1;
		A[2][i]=0;
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(A[0][i]<A[0][j]){
				if(A[1][i]<A[1][j]+1){
					A[1][i]=A[1][j]+1;
					l=max(l,A[1][i]);
					Nr[i]=Nr[j];
				}else if(A[1][i]==A[1][j]+1){
					Nr[i]+=Nr[j];
				}
			}
		}
	}
	for(int i=1;i<=n && k>=0;i++){
		if(A[1][i]==l){
			if(k>Nr[i]){
				k-=Nr[i];
			}else{
				fout<<i<<' ';
				l--;
			}
		}
	}
	return 0;
}
