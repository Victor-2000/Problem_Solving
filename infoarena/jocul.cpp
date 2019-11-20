//Condition of the problem: https://www.infoarena.ro/problema/jocul

#include <bits/stdc++.h>
 
using namespace std;
 
int n,S[1010];
long long sum=0,A[2][100010];
 
ifstream fin("jocul.in");
ofstream fout("jocul.out");
 
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>S[i];
	}
	A[0][S[0]]=sum=S[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=sum+S[i];j++)A[i%2][j]=0;
		for(int j=0;j<=sum;j++){
			if(A[(i+1)%2][j]){
				A[i%2][j+S[i]]=A[(i+1)%2][j]+S[i];
				A[i%2][abs(j-S[i])]=A[(i+1)%2][j];
				if(j-S[i]<0)A[i%2][S[i]-j]+=S[i]-j;
			}
		}
		sum+=S[i];
	}
	int k;
	for(k=0;k<=sum && !A[(n-1)%2][k];k++);
	if(A[(n-1)%2][k]>sum-A[(n-1)%2][k]){
		fout<<sum-A[(n-1)%2][k]<<' '<<A[(n-1)%2][k];
	}else fout<<A[(n-1)%2][k]<<' '<<sum-A[(n-1)%2][k];
	return 0;
}
