//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1428

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,A[1001],noc=0;
	cin>>n;
	while(n){
		noc++;
		printf("Case %d:\n",noc);
		for (int i=0;i<n;i++){
			cin>>A[i];
		}
		int q,cq,sol=10000000;
		cin>>q;
		for (int i=0;i<q;i++){
			cin>>cq;
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					if(i!=j && abs(cq-(A[i]+A[j]))<=abs(cq-sol))sol=A[i]+A[j];
				}
			}
			printf("Closest sum to %d is %d.\n",cq,sol);
		}
		cin>>n;
	}
	return 0;
}
