//Condition of the problem: https://www.infoarena.ro/problema/aiafarapalindroame

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
 
int n;
ll dif,same,M[2][2],B[2][2];
 
void p(){
	ll S[2][2]={{0,0},{0,0}};
	for(int i=0;i<2;i++){
		for(int k=0;k<2;k++){
			for(int j=0;j<2;j++){
				S[i][k]+=M[i][j]*M[j][k];
				S[i][k]%=MOD;
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			M[i][j]=S[i][j];
		}
	}
}
 
void fp(int k){
	if(k<=1){
		return;
	}
	fp(k/2);
	p();
	if(k%2){
		ll S[2][2]={{0,0},{0,0}};
		for(int i=0;i<2;i++){
			for(int k=0;k<2;k++){
				for(int j=0;j<2;j++){
					S[i][k]+=M[i][j]*B[j][k];
					S[i][k]%=MOD;
				}
			}
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				M[i][j]=S[i][j];
			}
		}	
	}
}
 
int main(){
	ifstream cin("aiafarapalindroame.in");
	ofstream cout("aiafarapalindroame.out");
	cin>>n;
	dif=26*25*25;
	same=26*25;
	if(n==1)cout<<"26\n";
	else if(n==2) cout<<"676\n";
	else if(n==3) cout<<dif+same;
	else{
		M[0][0]=B[0][0]=B[0][1]=M[0][1]=24;
		B[1][0]=M[1][0]=1;
		B[1][1]=M[1][1]=0;
		ll s=0;
		fp(n-3);
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(!j)s+=dif*M[i][j]%MOD;
				else s+=same*M[i][j]%MOD;
				s%=MOD;
			}
		}
		cout<<s;
	}
	return 0;
}
