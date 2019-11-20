//Condition of the problem: https://www.infoarena.ro/problema/maxsecv

#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin ("maxsecv.in");
ofstream fout ("maxsecv.out");
 
bool A[1000002];
int B[1000002];
 
int main(){
	int n;
	fin>>n;
	for(int i=0;i<n;i++) fin>>A[i];
	B[0]=A[0];
	int max1=0,max2=0;
	for(int i=1;i<=n;i++){
		if(A[i]) B[i]=B[i-1]+1;
		else if(max2<B[i-1])
				if(max1<B[i-1]){
					max2=max1;
					max1=B[i-1];
				}else max2=B[i-1];
	}
	fout<<max1+max2;
	return 0;
}
