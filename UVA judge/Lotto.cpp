//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=382
#include <bits/stdc++.h>
#define MAX 15

using namespace std;

int main(){
	int n,A[MAX];
	cin>>n;
	while(n){
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		for(int i1=0;i1<n-5;i1++){
			for(int i2=i1+1;i2<n-4;i2++){
				for(int i3=i2+1;i3<n-3;i3++){
					for(int i4=i3+1;i4<n-2;i4++){
						for(int i5=i4+1;i5<n-1;i5++){
							for(int i6=i5+1;i6<n;i6++){
								printf("%d %d %d %d %d %d\n",A[i1],A[i2],A[i3],A[i4],A[i5],A[i6]);
							}
						}
					}
				}
			}
		}
		cin>>n;
		if(n)cout<<'\n';
	}
	return 0;
}
