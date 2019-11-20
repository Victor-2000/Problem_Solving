//Condition of the problem: https://www.infoarena.ro/problema/permut

#include <bits/stdc++.h>
 
using namespace std;
 
# define NMAX 100100
 
ifstream fin("permut.in");
ofstream fout("permut.out");
 
int main(){
	int n;
	long long A[NMAX],B[NMAX],s=0;
	fin>>n;
	for(int i=0;i<n;i++) fin>>A[i];
	for(int i=0;i<n;i++) fin>>B[i];
	sort(A,A+n);
	sort(B,B+n);
	for(int i=0;i<n;i++) s+=(A[i]*B[i]);
	fout<<s;
	return 0;
}

