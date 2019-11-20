//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917

#include <bits/stdc++.h>

using namespace std;

int main(){
	int k,A[2][10010];
	while(cin>>k){
		int ymax=2*k,l=0;
			for(int y=k+1;y<=ymax;y++){
				double x=abs(k*y/(y-k));
				if(x!=1 && x==(int)x && x>=y && (double)k==(double)x*y/(double)(y+x)){
					A[0][l]=x;
					A[1][l++]=y;
				} 
			}
		cout<<l<<'\n';
		for(int i=0;i<l;i++){
			cout<<"1/"<<k<<" = 1/"<<A[0][i]<<" + 1/"<<A[1][i]<<'\n';
		}
	}
	return 0;
}
