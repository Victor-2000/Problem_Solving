//Condition of the problem: https://www.infoarena.ro/problema/perle2

#include<bits/stdc++.h>
using namespace std;
 
int n,k,s=0,sol=0,ind=0,c;
 
ifstream fin("perle2.in");
ofstream fout("perle2.out");
 
int main(){
	fin>>n>>k;
	for(int i=0;i<n;i++){
		fin>>c;
		s+=c-k;
		sol=max(s,sol);
		if(s<0){
			s=0;
			ind=i;
		}
	}
	fout<<sol;
	return 0;
}
