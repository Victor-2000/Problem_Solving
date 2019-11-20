//Condition of the problem: https://www.infoarena.ro/problema/next

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int N[1000010];
ll R,D;
 
ifstream fin("next.in");
ofstream fout("next.out");
 
void add(int *A, ll B)
{
      int i=1,t=0;
      while(t||i<=A[0]){
      	A[i]=(t+=A[i]+B%10)%10;
      	i++;
      	t/=10;
      	B/=10;
	  }
      A[0] = i - 1;
}
 
void div(int *A,ll B,ll &R){
	int i;
	for(i=A[0];i>=1;i--,R*=10){
		R=(A[i]+R)%B;
	}
	R/=10;
}
 
void write(int *A){
	for(int i=A[0];i>=1;i--)fout<<A[i];
	fout<<'\n';
}
 
void read(int *A){
	string s;
	fin>>s;
	A[0]=s.size();
	for(int i=A[0];i>=1;i--){
		A[i]=s[A[0]-i]-'0';
	}
}
 
int main(){
	read(N);
	fin>>D;
	R=0;
	div(N,D,R);
	if(R){
		D-=R;
		add(N,D);	
	}
	write(N);
	return 0;
}

