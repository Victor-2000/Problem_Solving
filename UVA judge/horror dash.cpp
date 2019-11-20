//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2899

# include <bits/stdc++.h>

using namespace std;

int t,n,c,m;

int main(){
	m=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",&c);
			m=max(m,c);
		}
		printf("Case %d: %d\n",i,m);
		m=0;
	}
	return 0;
}
