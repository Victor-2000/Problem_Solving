//Condition of the problem: https://www.infoarena.ro/problema/nodiv

#include <bits/stdc++.h>
 
using namespace std;
 
int t,X[10010],Y[10010];
 
ifstream fin("nodiv.in");
ofstream fout("nodiv.out");
 
int main(){
	fin>>t;
	while(t--){
		long long n,b=1;
		int x=0,y=0,nr=0;
		fin>>n;
		while(b<=n && x<39){
			b*=3;
			x++;
		}
		while(n){
			while(!(n%2)){
				n/=2;
				y++;
			}
			while(b>n){
				b/=3;
				x--;
			}
			n-=b;
			X[nr]=x;
			Y[nr++]=y;
		}
		fout<<nr<<' ';
		for(int i=0;i<nr;i++){
			fout<<Y[i]<<' '<<X[i]<<' ';
		}
		fout<<'\n';
	}
	return 0;
}

