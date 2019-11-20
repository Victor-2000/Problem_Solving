//Condition of the problem: https://www.infoarena.ro/problema/oras

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("oras.in");
ofstream fout("oras.out");
 
int n;
bool S[7][7]; 
 
int main(){
	fin>>n;
	if(n%2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j<i){
					if(i%2)fout<<(j%2);
					else fout<<!(j%2);
				}else if(j>i){
					if(i%2)fout<<!(j%2);
					else fout<<(j%2);
				}else fout<<0;
			}
		fout<<'\n';
		}
	}else if(n==4) fout<<-1;
	else{
		S[1][4]=1;
		S[1][5]=1;
		S[2][1]=1;
		S[2][3]=1;
		S[2][5]=1;
		S[3][1]=1;
		S[3][4]=1;
		S[3][6]=1;
		S[4][2]=1;
		S[4][5]=1;
		S[5][3]=1;
		S[5][6]=1;
		S[6][1]=1;
		S[6][2]=1;
		S[6][4]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i<=6 && j<=6){
					fout<<S[i][j];
				}else{
					if(j<i){
						if(i%2)fout<<(j%2);
						else fout<<!(j%2);
					}else if(j>i){
						if(i%2)fout<<!(j%2);
						else fout<<(j%2);
					}else fout<<0;
				}
			}
			fout<<'\n';
		}
	}
	return 0;
}
