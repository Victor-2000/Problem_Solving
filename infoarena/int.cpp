//Condition of the problem: https://www.infoarena.ro/problema/int

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("int.in");
ofstream fout("int.out");
 
struct interval{
	long st,dr;
};
 
interval A[50001];
 
bool isb(interval a, interval b){
	return a.dr<b.dr;
}
 
int main(){
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
		fin>>A[i].st>>A[i].dr;
	sort(A,A+n,isb);
	interval last=A[0];
	int sol=1;
	for(int i=1;i<n;i++){
		if(last.dr<=A[i].st){
			sol++;
			last = A[i];
		}
	}
	fout<<sol;
	return 0;
}
