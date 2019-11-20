//Condition of the problem: https://www.infoarena.ro/problema/nrtri

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("nrtri.in");
ofstream fout("nrtri.out");
 
int v,n,s=0,A[801],ni;
 
int cbin(int st,int dr){
	int m=st+(dr-st)/2;
	if(m!=st){
		 if (st<dr){
			if(A[m]<=v){ 
			 return cbin(m,dr);
			} else return cbin(st,m-1);
		} else if (A[st]<=v){
			return st-ni+1;
		}
	} else if (A[dr]<=v) return dr-ni+1;
		else if (A[st]<=v) return st-ni+1; 
	return 0;
}
 
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>A[i];
	}
	sort(A,A+n);
	for(int i=0;i<n-2;i++){
		for (int j=i+1;j<n-1;j++){
			v=A[i]+A[j];
			ni=j+1;
			s+=cbin(j+1,n-1);
		} 
	}
	fout<<s;
	return 0;
}
