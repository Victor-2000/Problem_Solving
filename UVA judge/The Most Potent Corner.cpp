//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1205

#include <bits/stdc++.h>

using namespace std;

const int MAX = 32769;

int A[MAX],P[MAX];

int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<(1<<n);i++){
			cin>>A[i];	
			P[i]=0;
		}
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				P[i]+=A[i^(1<<j)];
			}	
		}
		int vm=0;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				int vc=0;
				vc=P[i]+P[i^(1<<j)];
				if(vm<vc)vm=vc;
			}	
		}
		cout<<vm<<'\n';
	}
	
	return 0;
}
