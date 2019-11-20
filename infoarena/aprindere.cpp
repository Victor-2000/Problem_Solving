//Condition of the problem: https://www.infoarena.ro/problema/aprindere

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("aprindere.in");
ofstream fout("aprindere.out");
 
int main(){
	int n,m,sol=0;
	fin>>n>>m;
	int T[1010];
	vector <int> CA[1010];
	bool C[1010];
	bool a;
	for(int i = 0;i<n;i++)
		fin>>C[i];
	for(int i = 0;i<m;i++){
		int x,nr;
		fin>>x;
		fin>>T[x]>>nr;
		for (int j = 0;j<nr;j++){
			int c;
			fin>>c;
			CA[x].push_back(c);
		}
	}
	for (int i=0;i<n;i++){
		if( T[i] && !C[i]){
			sol+=T[i];
			for (int j=0;j<CA[i].size();j++)
				C[CA[i][j]] = !C[CA[i][j]];
		}
	}
	fout<<sol;
	return 0;
}
