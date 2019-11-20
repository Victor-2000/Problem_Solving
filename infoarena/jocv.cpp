//Condition of the problem: https://www.infoarena.ro/problema/joctv

#include <bits/stdc++.h>
using namespace std;
 
int n,A[105][105];
 
ifstream fin("joctv.in");
ofstream fout("joctv.out");
 
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin>>A[i][j];
			if(i)A[i][j]+=A[i-1][j];
			if(j)A[i][j]+=A[i][j-1];
			if(j&&i)A[i][j]-=A[i-1][j-1];
		}
	}
	int sum=0,sol=0;
	for(int i=0;i<n;i++)
		for(int i1=i;i1<n;i1++){
			int j=0;
			if(i==3 && i1==4)
			j=0;
			for(int j1=j;j1<n;j1++){
				sum=0;
				if(i)sum-=A[i-1][j1];
				if(j)sum-=A[i1][j-1];
				if(j&&i)sum+=A[i-1][j-1];
				sum+=A[i1][j1];
				if(sum<0)j=j1+1;
				sol=max(sum,sol);
			}
		}
	fout<<sol;
	return 0;
}
