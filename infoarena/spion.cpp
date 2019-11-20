//Condition of the problem: https://www.infoarena.ro/problema/spion

#include <bits/stdc++.h>
#define MOD 100003
#define MAX 10001000
#define ll long long
using namespace std;
 
ifstream fin("spion.in");
ofstream fout("spion.out");
 
ll F[MAX];
 
//Determina inversul modular
ll DVM(ll a,ll b, ll &x, ll &y){
	if(b==0){
		x=1;y=0;
		return a;
	}else{
		ll x0,y0,s=DVM(b,a%b,x0,y0);
		x=y0;
		y=x0-y0*(a/b);
		return s;
	}	
}
 
ll f(ll n,ll M){//Functia pentru factorial
	if (F[n]) return F[n];
	else return F[n]=(f(n-1,M)*n)%M;
}
 
ll MC(ll a,ll b,ll M){//Combinari cu modul
	ll x,y;
	DVM(M,(f(a-b,M)*f(b,M))%M,x,y);
	while(y<0)y+=M;
	return (f(a,M)*y)%M;
}
 
int main(){
	int p;
	string s;
	fin>>p>>s;
	ll jc=1,l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='E')jc++;
	}
	memset(F,0,l);
	F[0]=F[1]=1;
	if(p==1){
		fout<<jc;
	}
	else{
		fout<<MC(l,jc-1,MOD)<<'\n';
	}
	return 0;
}
