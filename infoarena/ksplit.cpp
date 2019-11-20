//Condition of the problem: https://www.infoarena.ro/problema/ksplit

#include <bits/stdc++.h>
 
using namespace std;
 
int dmax=0,lmax=0,n,nr[100010],iM[2][100010],im[2][100010],sm=0,sM=0,indm=1,indM=1,M[2][100010],m[2][100010];
 
ifstream fin("ksplit.in");
ofstream fout("ksplit.out");
 
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>nr[i];
		sM+=nr[i];
		sm+=nr[i];
		M[0][i]=sM;
		m[0][i]=sm;
		M[1][i]=indM++;
		m[1][i]=indm++;
		if(sM<0){
			sM=0;
			indM=1;
		}
		if(sm>0){
			sm=0;
			indm=1;
		}
	}
	sm=sM=0;
	indm=indM=1;
	for(int i=n-1;i>=0;i--){
		sM+=nr[i];
		sm+=nr[i];
		iM[0][i]=sM;
		im[0][i]=sm;
		iM[1][i]=indM++;
		im[1][i]=indm++;
		if(sM<0){
			sM=0;
			indM=1;
		}
		if(sm>0){
			sm=0;
			indm=1;
		}
	}
	dmax=lmax=-1000000;
	for(int i=0;i<n-1;i++){
		long long d1=M[0][i]-im[0][i+1],l1=M[1][i]+im[1][i+1],d2=iM[0][i+1]-m[0][i],l2=iM[1][i+1]+m[1][i];
		if(d1>dmax||(d1==dmax && l1>lmax)){
			dmax=d1;
			lmax=l1;
		}
		if(d2>dmax ||(d2==dmax && l2>lmax)){
			dmax=d2;
			lmax=l2;
		}
	}
	fout<<dmax<<'\n'<<lmax;
	return 0;
}
