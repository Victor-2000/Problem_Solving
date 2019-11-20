//Condition of the problem: https://www.infoarena.ro/problema/copii

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("copii.in");
ofstream fout("copii.out");
 
int n,V[11][3],P[11];
long long pos=0;
 
void bk(int k){//k-adancimea (nr de cifre folosite sau copii inclusi)
	if(k>n){	
		int i;
		for(i=1;i<=n && V[i][2]!=0;i++){
			for(int j=1;j<=n && V[j][1]!=0;j++){
				if(i!=j && !(V[i][2]&V[j][1])){
					return;
				}
			}	
		}
		if(i>2){
			pos++;		
		}
		return;
	} 
	for(int i=1;i<=n && (V[i-1][1]!=0 || i==1);i++){
		V[i][1]|=(1<<k);
		int init=V[i][2];
		V[i][2]|=P[k];
		bk(k+1);
		V[i][2]=init;
		V[i][1]-=(1<<k);
	}
	return;
}
 
int main (){
	fin>>n;
	for(int i=1;i<=n;i++){
		V[i][1]=V[i][2]=P[i]=0;
		for(int j=1;j<=n;j++){
			char c;
			fin>>c;
			if(j!=i)
			P[i]+=(c-'0')<<j;		
		}
	}
	bk(1);
	fout<<pos<<'\n';
	return 0;
}
