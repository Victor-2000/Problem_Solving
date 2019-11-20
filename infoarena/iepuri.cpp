//Condition of the problem: https://www.infoarena.ro/problema/iepuri

#include <bits/stdc++.h>
#define MOD 666013
#define ll long long
using namespace std;
 
int A[3],X[3],n,t;
ll M[3][3],B[3][3];
 
void p(){
	ll S[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	for(int i=0;i<3;i++){
		for(int k=0;k<3;k++){
			for(int j=0;j<3;j++){
				S[i][k]+=(M[i][j]*M[j][k])%MOD;
			}
			S[i][k]%=MOD;
		}
	}
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)M[i][j]=S[i][j];
}
 
void fp(int k){
	if(k==1) return;
	fp(k/2);
	p();
	if(k%2){
		ll S[3][3]={{0,0,0},{0,0,0},{0,0,0}};
		for(int i=0;i<3;i++){
			for(int k=0;k<3;k++){
				for(int j=0;j<3;j++){
					S[i][k]+=(M[i][j]*B[j][k])%MOD;
				}
				S[i][k]%=MOD;
			}
		}
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)M[i][j]=S[i][j];
	}
}
 
int main(){
	ifstream cin("iepuri.in");
	ofstream cout("iepuri.out");
	cin>>t;
	while(t--){
		M[0][0]=M[0][1]=M[1][1]=M[2][0]=0;
		B[0][0]=B[0][1]=B[1][1]=B[2][0]=0;
		M[1][0]=B[1][0]=M[2][1]=B[2][1]=1;
		for(int i=0;i<3;i++)cin>>X[i];
		cin>>M[2][2]>>M[1][2]>>M[0][2]>>n;
		B[0][2]=M[0][2];
		B[1][2]=M[1][2];
		B[2][2]=M[2][2];
		if(n==0){
			cout<<M[2][2]<<'\n';
		}else if(n==1){
			cout<<M[1][2]<<'\n';
		}else if(n==2){
			cout<<M[0][2]<<'\n';
		}else{
			fp(n-2);
			ll s=0;
			for(int i=0;i<3;i++){
				s+=(M[i][2]*X[i])%MOD;
				s%=MOD;
			}
			cout<<s<<'\n';
		}	
	}
	return 0;
}
