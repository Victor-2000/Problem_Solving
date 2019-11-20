//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3701

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int main(){
	int t,n,A[MAX];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		int nr=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(A[j]<=A[i])nr++;
			}
		}
		cout<<nr<<'\n';
	}
	return 0;
}
