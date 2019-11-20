//Condition of the problem: https://www.infoarena.ro/problema/orase

#include <bits/stdc++.h>
using namespace std;
ifstream fin("orase.in");
ofstream fout("orase.out");
int m,mi=1000010,n,A[1000010];
int main(){
	fin>>m>>n;
	memset(A,0,m);
	for(int i=0;i<n;i++){
		int d,l;
		fin>>d>>l;
		A[d]=max(A[d],l);
		mi=min(mi,d);
	}
	int s=A[mi],sol=0;
	for(int i=mi+1;i<=m;i++){
		if(!A[i])s++;
		else{
			int sp=s;
			s+=A[i]+1;
			sol=max(sol,s);
			s=max(A[i],sp+1);
		}
	}
	fout<<sol<<'\n';
}

