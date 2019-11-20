//Condition of the problem: https://www.infoarena.ro/problema/bilete

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("bilete.in");
ofstream fout("bilete.out");
 
int n,ng;
long long t=0,to=0;
int TO[4],T[4];
int ogl(int t){
	return t=n-t+1;
}
 
void bk(int k){
	if(k<=ng){
		int ic=T[k-1]/10,jc=T[k-1]%10+1,nmax=n*10+n-ng+k;
		if (!ic) ic=1;
		for(int i=ic;i<=n;i++){
			for(int j=jc;j<=n;j++){
				T[k]=i*10+j; 
				if(T[k]<=nmax)
					bk(k+1);
				T[k]=0;
			}
			jc=1;
		}
	}else{	
		for(int i=1;i<=ng;i++){
			int og;
			TO[i] = T[i];
			og=ogl(TO[i]%10);
			TO[i]-=TO[i]%10;
			TO[i]+=og;
		}
		sort(TO+1,TO+1+ng);
		for (int i=1;i<=ng;i++){
			to*=100;
			t*=100;
			t+=T[i];
			to+=TO[i];
			//TO[i]=0;
		}
		if(t<=to){
			fout<<t<<'\n';
		}
		to=0;
		t=0;
	}	
}
 
int main(){
	T[0]=0;
	fin>>n>>ng;
	bk(1);
	cerr << clock() * 1000.0 / CLOCKS_PER_SEC;
	return 0;
}
