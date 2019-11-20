//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3778

#include <bits/stdc++.h>

using namespace std;

struct soldier {
	int lb,rb;	
};

soldier A[100010];

int main(){
	int b,s;
	scanf("%d %d",&s,&b);
	while(s){
		for(int i=1;i<s;i++){
			A[i].lb=i-1;
			A[i].rb=i+1;
		} 
		A[s].rb=0;
		A[s].lb=s-1;
		while(b--){
			int l,r;
			scanf("%d %d",&l,&r);
			if(A[l].lb) cout<<A[l].lb<<' ';
			else cout<<"* ";
			if(A[r].rb) cout<<A[r].rb<<'\n';
			else cout<<"*\n";
			A[A[l].lb].rb=A[r].rb;
			A[A[r].rb].lb=A[l].lb;
		}
		cout<<"-\n";
		scanf("%d %d",&s,&b);
	}
	return 0;
}
