//Condition of the problem: https://www.infoarena.ro/problema/carnati

#include <bits/stdc++.h>
#define M -100000000
using namespace std;
 
struct client{
	int t,p;
}C[2010];
 
int c,n,sol=M;
 
ifstream fin("carnati.in");
ofstream fout("carnati.out");
 
bool cmp(client a,client b){return a.t<b.t;}
 
int DP(int ind){
	int ans=M,sum=0,g=0;
	for(int i=1;i<=n;i++){
		sum=max(sum-(C[i].t-C[i-1].t)*c,0);
		if(C[ind].p<=C[i].p)sum+=C[ind].p;
		ans=max(ans,sum-c);
	}
	return ans;
}
 
int main(){
	fin>>n>>c;
	C[0].t=C[0].p=0;
	for(int i=1;i<=n;i++){
		fin>>C[i].t>>C[i].p;
	}
	sort(C+1,C+n+1,cmp);
	for(int i=1;i<=n;i++){
		sol=max(sol,DP(i));
	}
	fout<<sol;
	return 0;
}
