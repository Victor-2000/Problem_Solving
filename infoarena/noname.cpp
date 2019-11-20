//Condition of the problem: https://www.infoarena.ro/problema/noname

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("noname.in");
ofstream fout("noname.out");
 
 
int n,P1[1001],P2[1001],s=1;
bool A[1001][1001];
 
 
int main(){
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>P1[i];
	}
	for(int i=1;i<=n;i++){
		fin>>P2[i];
	}
	fout<<s<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(P1[i]+P2[j]>n){
				fout<<'1'<<' ';
			}
			else fout<<'0'<<' ';
	 fout<<'\n';
	}
	return 0;
}
