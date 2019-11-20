//Condition of the problem: https://www.infoarena.ro/problema/string

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("string.in");
ofstream fout("string.out");
 
int log(int n){
	int l=0;
	if(n==1) return 1;
	for(l=0;(1<<l)<n;l++);
	if(n==(1<<(l-1))) return l-1;
	else return l; 
}
 
string trans(int n, int ne){
	string sol="";
	while(n){
		while(n%2==0){
			n/=2;
			sol="a"+sol;
		}
		sol="b"+sol;
		n/=2;	
	}
	while(sol.size()<ne)sol="a"+sol;
	return sol;
}
 
int n,bc[21];
bool iP[21][530000];
 
int main (){
	fin>>n;
	int lg=log(n);
	for(int i=0;i<19;i++){
		bc[i]=0;
		for(int j=0;j<529000;j++){
			iP[i][j]=0;
		}
	}
	char c;
	for(int i=1;i<=n;i++){
		fin>>c;
		int j;
		if(i<=lg)j=i;
		else j=lg;
		for(;j>0;j--){
			bc[j]=bc[j-1]*2;
			if(c=='b')bc[j]++;
			iP[j][bc[j]]=1;
		}
	}
	
	for(int i=1;i<=lg;i++){
		for(int j=0;j<(1<<i);j++){
			if(!iP[i][j]){
				fout<<i<<'\n';
				fout<<trans(j,i);
				return 0;
			}
		}
	}
    return 0;
}
