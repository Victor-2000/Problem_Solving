//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2548

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,A[8][8];
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>A[i][j];
			}
		}
		int pos[]={0,1,2,3,4,5,6,7},msum=10000000;
		bool nfree[8];
		do{
			int sum=0;				
			memset(nfree,0,8);
			for(int i=0;i<n;i++){
				int m=1000000,jp;
				for(int j=0;j<n;j++){
					if(A[pos[i]][j]<m && !nfree[j]){
						m=A[pos[i]][j];
						jp=j;
					}
				}
				nfree[jp]=1;
				sum+=m;	
			}
			msum=min(sum,msum);
		}while(next_permutation(pos,pos+n));
		cout<<msum<<'\n';
	}
	return 0;
}
