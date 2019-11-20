//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=637

#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	while(m && n){
		int s=0;
		if(m==1||n==1) s=max(m,n);
		else if(m==2){
			s=n/4*4;
			if(n%4==1) s+=2;
			else if(n%4>1) s+=4;
		} else if(n==2){
			s=m/4*4;
			if(m%4==1) s+=2;
			else if(m%4>1) s+=4;
		}
		else s=(m*n+1)/2;
		printf("%d knights may be placed on a %d row %d column board.\n",s,m,n);
		scanf("%d %d",&m,&n);
	}
	return 0;
}
