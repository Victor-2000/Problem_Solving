//Condition of the problem: https://www.infoarena.ro/problema/3secv

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("3secv.in");
ofstream fout("3secv.out");
 
long long s1=0,s2=0,s3=0,dif=-1,A[1000001];
int p1,p2,n;
 
int main(){
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>A[i];
		if(i>=2) s3+=A[i];
	}
	s1=A[1];
	int j=1;
	for(int i=2;i<=n-1;i++){
		s2+=A[i];
		s3-=A[i];
		while(j+1<i && abs(s1-s2)>abs(s1+A[j+1]-(s2-A[j+1]))){
			j++;
			s1+=A[j];
			s2-=A[j];
		}
		long long dc = max(max(s1,s2),s3)-min(min(s1,s2),s3);
		if(dif==-1 || dif>dc){
			dif=dc;
			p1=j;
			p2=i;
		}
	}
	fout<<p1<<' '<<p2;
	return 0;
}
