//Condition of the problem: https://www.infoarena.ro/problema/concert2

#include <bits/stdc++.h>
#define NMAX 3000
using namespace std;
 
int A[2][NMAX],up,m=-1,dw,n,L[NMAX],C[NMAX];
 
int main(){
	ifstream cin("concert2.in");
	ofstream cout("concert2.out");
	cin>>n>>up>>dw;
	A[0][0]=L[0]=A[1][0]=1;
	for(int i=0;i<n;i++){
		cin>>C[i];
		for(int j=i;j>=0;j--){
			if(C[i]!=C[j]){
				if(L[j]>=L[i]){
					if(C[j]<C[i]){
						if(A[0][j]<up){
							L[i]=L[j]+1;
							A[0][i]=A[0][j]+1;
							A[1][i]=1;
						}
					}else if(A[1][j]<dw){
						L[i]=L[j]+1;
						A[0][i]=1;
						A[1][i]=A[1][j]+1;
					}
				}
			}
		}
		if(m<L[i])m=L[i];
	}
	cout<<m;
	return 0;
}
