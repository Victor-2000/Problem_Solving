//Condition of the problem: https://www.infoarena.ro/problema/triunghi
#include <bits/stdc++.h>
 
using namespace std;
 
int si=0,T[20],Tr[20][20],A[1000010],n,s,mn;
 
ifstream fin("triunghi.in");
ofstream fout("triunghi.out");
 
int main(){
	fin>>n>>s;
	T[1]=Tr[n][1]=1;//Generam tabelul de elemente
	for(int i=2;i<=n;i++){
		Tr[n][i]=1;
		for(int j=i;j>=1;j--){
			int s=1;
			if(j-1)s+=T[j-1];
			T[j]+=s;
			if(i==n){
				si+=T[j];
			}
		}
	}
	A[si]=-1;
	bool stop=0;
	int ind=s;
	for(int i=si;i<=s&&!stop;i++){
		if(A[i]){
			for(int j=1;j<=n&&!stop;j++){
				if(i+T[j]<=s)A[i+T[j]]=j;
				if(i+T[j]==s){
					stop=true;
					break;
				}else if((s-i-T[j])%T[j]==0){
					stop=true;
					ind=i+T[j];
					Tr[n][j]+=(s-i-T[j])/T[j];
					break;
				}	
			}
		}
	}
	if(A[ind]){
		int p=ind;
		while(A[p]!=-1){
			Tr[n][A[p]]++;
			p-=T[A[p]];
		}
		for(int i=n-1;i>0;i--){
			for(int j=1;j<=i;j++){
				Tr[i][j]=Tr[i+1][j+1]+Tr[i+1][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				fout<<Tr[i][j]<<' ';
			}
			fout<<'\n';
		}
	}else fout<<"imposibil";	
	return 0;
}
