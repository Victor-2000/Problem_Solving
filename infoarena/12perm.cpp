//Condition of the problem: https://www.infoarena.ro/problema/12perm

#include <bits/stdc++.h>
 
using namespace std;
 
int A[4],n,k=0;
 
ifstream fin("12perm.in");
ofstream fout("12perm.out");
 
int main(){
	fin>>n;
	A[1]=12;
	A[2]=6;
	A[3]=2;
	if(n==1)fout<<1;
	else if(n<=4)fout<<A[n-1];
	else{
		for(int i=5;i<=n;i++){
			k=(A[1]+A[3]+2*(i-2))%1048576;
			A[3]=A[2];
			A[2]=A[1];
			A[1]=k;
		}
		fout<<k;
	}
}
