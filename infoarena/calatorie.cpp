//Condition of the problem: https://www.infoarena.ro/problema/calatorie

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll A[55][510];
int N,H,n,t;
 
ll p4(ll c){
	ll s=c*c;
	s*=s;
	return s;
}
 
int main(){
	ifstream cin("calatorie.in");
	ofstream cout("calatorie.out");
	cin>>t;
	while(t--){
		cin>>n;
		n--;
		int l=510;
		for(int i=0;i<n;i++){
			cin>>N>>H;
			for(int j=0;j<l;j++)A[i][j]=-1;
			if(!i){
				A[0][0]=N;
				A[0][H]=0;
			}else for(int j=0;j<l;j++){
				if(j>=H && A[i-1][j-H]!=-1){
					if(A[i][j]==-1 || A[i][j]>A[i-1][j-H])A[i][j]=A[i-1][j-H];
				}
				if(A[i-1][j]!=-1){
					if(A[i][j]==-1 || A[i][j]>A[i-1][j]+N)A[i][j]=A[i-1][j]+N;
				} 
			}
		}
		if(!n){
			cout<<"Consumul minim = 0.\n";
			continue;
		}
		ll a=-1,b;//a-hyper
		for(int j=0;j<l;j++){
			if(A[n-1][j]!=-1)
			if((a==-1)||(a>=j && b>=A[n-1][j])||(p4(j)+A[n-1][j]<p4(a)+b)){
				a=j;
				b=A[n-1][j];
			}
		}
		cout<<"Consumul minim = "<<p4(a)+b<<".\n";
	}
	return 0;
}
