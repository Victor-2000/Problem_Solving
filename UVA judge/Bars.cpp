//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886

#include <bits/stdc++.h>

using namespace std;

int const MAX=1<<20;

int val[21];

int main(){
	int t;
	cin>>t;
	while(t--){
		int L,n;
		bool sol=false;
		cin>>L;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>val[i];
		}
		for(int i=1;i<MAX;i++){
			int sum=0;
			for(int j=0;j<n;j++)if(i&(1<<j))sum+=val[j];
			if (sum==L){
				sol=true;
				break;
			}
		}
		if(sol)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
