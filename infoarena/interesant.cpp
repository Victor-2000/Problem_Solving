//Condition of the problem: https://www.infoarena.ro/problema/interesant

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("interesant.in");
ofstream fout("interesant.out");
 
struct sir{
	int l,p;
	string s;
};
 
bool cmp(sir a,sir b){
	return a.l>b.l||(a.l==b.l && a.s<b.s);
}
 
bool contine(sir B,sir A){
	int ind = 0;
	for(int i=0;i<A.l;i++){
		if(A.s[i]==B.s[ind])ind++;
	}
	return ind==B.l;
}
 
sir A[501],B[501];
 
int main(){
	int d,n;
	fin>>d>>n;
	for(int i=0;i<n;i++){
		fin>>A[i].s;
		A[i].l=A[i].s.size();
		A[i].p=i;
		B[i]=A[i];
	}
	sort(A,A+n,cmp);
	if(d==1){
		fout<<A[0].s;
	} else {
		bool NEI[n];
		int nr=n;
		for(int i=0;i<n;i++) NEI[i]=0;
		for(int i = n-1;i>0;i--){
			for(int j = i-1;j>=0;j--){
				if(contine(A[i],A[j]) && !NEI[A[i].p]){
					NEI[A[i].p]=1;
					nr--;
				}
			}
		}
		fout<<nr<<'\n';
		for(int i=0;i<n;i++){
			if(!NEI[i]) fout<<B[i].s<<'\n';
		}
	}
	return 0;
}
