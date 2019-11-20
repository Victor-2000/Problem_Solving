//Condition of the problem: https://www.infoarena.ro/problema/aladdin2

#include <bits/stdc++.h>
 
using namespace std;
 
const int BASE=10000000; 
 
int A[10000000],n,m;
 
ifstream fin("aladdin2.in");
ofstream fout("aladdin2.out");
 
void prod(int *A,int b){
	int i=1,t=0;
	while(i<=A[0]||t){
		A[i]=(t+=A[i]*b)%BASE;
		i++;
		t/=BASE;
	}
	A[0]=i-1;
}
 
void sum(int *A,int b){
	int i=1,t=0;
	A[1]+=b;
	while(t){
		A[i]=(t=A[i])%BASE;
		i++;
		t/=BASE;
	}
	if(A[0]<i-1)A[0]=i-1;
}
 
void write(int *A){
	fout<<A[A[0]];
	for(int i=A[0]-1;i>=1;i--){
		for(int x=BASE;x/10>A[i];x/=10){
			fout<<'0';	
		}
		fout<<A[i];
	}
	fout<<'\n';
}
 
int main(){
	fin>>n>>m;
	if(n>m)swap(n,m);
	int dif=n-2;
	A[0]=1;
	A[1]=2;
	if(n==2){
		for(int i=2;i<=m;i++){
			prod(A,2);
		}
		sum(A,2);
	}else{
		for(int i=2;i<=m-dif;i++){
			prod(A,2);
		}
		sum(A,2);
		for(int i=1;i<=dif;i++){
			sum(A,1);
			prod(A,2);
		}	
	}
	write(A);
	return 0;
}

