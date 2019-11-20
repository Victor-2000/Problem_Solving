//Condition of the problem: https://www.infoarena.ro/problema/ksecv3

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("ksecv3.in");
ofstream fout("ksecv3.out");
 
vector <int> I;
long long A[100001]; 
 
int main(){
	int n,k;
	long long s=0;
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		fin>>A[i];
		s+=A[i];
	}
	int m=s/k;
	s=0;
	for(int i=1;i<=n;i++){
		s+=A[i];
		if(s==m){
			I.push_back(i);
			s=0;
		}else if(s>m){
			fout<<-1;
			return 0;
		}	
	}
	for(int i = 0;i<I.size();i++)
		fout<<I[i]<<' ';
	return 0;
}
