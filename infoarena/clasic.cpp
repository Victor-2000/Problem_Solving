//Condition of the problem: https://www.infoarena.ro/problema/clasic

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("clasic.in");
ofstream fout("clasic.out");
 
int main(){
	int t;
	fin>>t;
	for (int i=0;i<t;i++){
		int n,s,c;
		fin>>n;
		s=0;
		for(int j=0;j<n;j++){
			fin>>c;
			s^=c;
		}
		fout<<s<<'\n';
	}
	return 0;
}

