//Condition of the problem:https://www.infoarena.ro/problema/granita

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin ("granita.in");
ofstream fout ("granita.out");
 
struct seg{
	int a,b;
};
 
bool cmp(seg a,seg b){
	return a.b>b.b;
}
 
int main(){
	int n,sol=0;
	seg A[16001];
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>A[i].a>>A[i].b;
	}
	sort(A,A+n,cmp);
	int cont = A[0].a;
	for(int i=1;i<n;i++){
		if(cont<A[i].a){
			sol++;
		} else 	cont = A[i].a;
	}
	fout<<sol;
	return 0;
}
