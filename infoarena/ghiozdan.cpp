//Condition of the problem: https://www.infoarena.ro/problema/ghiozdan

#include <bits/stdc++.h>
 
using namespace std;
 
int g,G[3][75100],V[210];
 
ifstream fin("ghiozdan.in");
ofstream fout("ghiozdan.out");
 
int main(){
	int n,x,m=0;
	fin>>n>>g;
	for (int i=1;i<=n;i++){
		fin>>x;
		V[x]++;
		if (m<x) m=x;
	}
	G[0][0]=1;
	for (int i=m;i>0;i--)
		if(V[i])
		for (int j = g-i;j>=0;j--)
			if(G[0][j])
				for (int k=1;k<=V[i];k++){
					if(j+k*i>g || G[0][j+k*i]) break;
					G[0][j+k*i] = G[0][j]+k;
					G[1][j+k*i] = i;
				}
	for (int i=g;i>0;i--){
		if(G[0][i]){
			fout<<i<<' '<<G[0][i]-1<<'\n';
			while(i){
				fout<<G[1][i]<<'\n';
				i -= G[1][i];
			}
			return 0;
		}
	}
	return 0;
}
