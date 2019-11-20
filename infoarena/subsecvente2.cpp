//Condition of the problem: https://www.infoarena.ro/problema/subsecvente2

#include <bits/stdc++.h>
#define NMAX 50010
using namespace std;
 
string s,sc;
int V[2][NMAX],C[NMAX],n,vn,sol;
 
void radix(int st,int dr,int c,bool m){
	int stc=st-1,drc=dr+1,MA=0,MB=0;
	for(int i=st;i<=dr;i++){
		int x=V[m][i];
		if(C[x]!=C[x+c])continue;
		if(s[x+c]=='a'){
			stc++;
			MA|=C[x];
			V[!m][stc]=x;
		}else{
			drc--;
			MB|=C[x];
			V[!m][drc]=x;
		}
	}
	if(MA==vn){
		sol=max(sol,c+1);
		radix(st,stc,c+1,!m);
	}
	if(MB==vn){
		sol=max(sol,c+1);
		radix(drc,dr,c+1,!m);
	}
}
 
int main(){
	ifstream cin("subsecvente2.in");
	ofstream cout("subsecvente2.out");
	cin>>n;
	vn=(1<<n)-1;
	for(int i=0;i<n;i++){
		cin>>sc;
		int l=s.size();
		s+=sc;
		for(int j=l;j<s.size();j++){
			V[0][j]=j;
			C[j]=1<<i;	
		}
	}
	radix(0,s.size()-1,0,0);
	cout<<sol;
	return 0;
}
