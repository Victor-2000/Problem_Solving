//Condition of the problem: https://www.infoarena.ro/problema/100m

#include <bits/stdc++.h>
#define MOD 666013
 
using namespace std;
 
ifstream fin("100m.in");
ofstream fout("100m.out");
 
int n;
long long H[5005],sol=0;
 
int main(){
	fin>>n;
	H[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=n;j>=1;j--){
			sol=0;
			sol=(((H[j-1]*j)%MOD)+((H[j]*j)%MOD))%MOD;
			H[j]=sol;
		}
	}
	sol=0;
	for(int i=1;i<=n;i++){
		sol=(sol+H[i])%MOD;
	}
	fout<<sol;
	return 0;
}
