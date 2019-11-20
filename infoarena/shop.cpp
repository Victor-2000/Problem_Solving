//Condition of the problem: https://www.infoarena.ro/problema/shop

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("shop.in");
ofstream fout("shop.out");
 
struct moneda{
	int a,b,ord;
};
 
bool cmp(moneda m1,moneda m2){
	return m1.a>m2.a;
}
 
int main(){
	moneda M[31];
	long long l,s=0;
	int n,c,S[31];
	fin>>n>>c>>l;
	for(int i=0;i<n;i++){
		fin>>M[i].a>>M[i].b;
		M[i].ord = i;
	}
	sort(M,M+n,cmp);
	for(int i=0;i<n;i++){
		long long val = pow(c,M[i].a),nr = l/val; 
		if (nr>M[i].b) nr=M[i].b;
		S[M[i].ord]=nr;
		s+=nr;
		l-=val*nr;
	}
	fout<<s<<'\n';
	for(int i=0;i<n;i++){
		fout<<S[i]<<' ';
	}
	return 0;
}
