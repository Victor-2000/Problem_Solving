//Condition of the problem: https://www.infoarena.ro/problema/reactivi

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");
 
struct segment{ 
	int x,y;
};
 
segment A[8001];
int s;
 
bool isb(segment a, segment b)
{
	return a.y<b.y;
}
 
int main(){
	int n;
	fin>>n;
	s=1;
	for (int i=0;i<n;i++){
		fin>>A[i].x>>A[i].y;
	}
	
	sort(A,A+n,isb);
	int y=A[0].y;
	for (int i=1;i<n;i++){
		if(y>=A[i].x) y=min(y,A[i].y);
		else{
			s++;
			y=A[i].y;
		} 
	}
	fout<<s;
	return 0;
}
