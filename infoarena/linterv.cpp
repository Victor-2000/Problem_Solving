//Condition of the problem: https://www.infoarena.ro/problema/linterv

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("linterv.in");
ofstream fout("linterv.out");
 
struct interval{
	int st,dr,l;
};
 
vector <interval> A;
 
bool cmp(interval a,interval b){
	return a.dr>b.dr;
}
 
int main(){
	int t;
	fin>>t;
	for(int i=0;i<t;i++){
		int n,s=0;
		interval a;
		fin>>n;
		for(int j=0;j<n;j++){
			fin>>a.st>>a.dr;
			a.l = a.dr-a.st;
			s += a.l;
			A.push_back(a); 
		}
		sort(A.begin(),A.end(),cmp);
		interval c = A[0];
		for(int j=1;j<n;j++){
			if(c.st<A[j].dr){
				if(c.st<A[j].st) s-=A[j].l;
				else { s-=A[j].dr - c.st;
					c.st = A[j].st;
				}  
			} else c = A[j];
		}
		A.clear();
		fout<<s<<'\n';
	}
	return 0;
}
