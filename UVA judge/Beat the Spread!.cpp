//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1753

#include <bits/stdc++.h>

using namespace std;

int n,s,d;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&s,&d);
		if(s%2==d%2 && d<=s && d>=0 && s>=0){
			int n1=0,n2=0;
			n2=(s-d)/2;
			n1=s-n2;
			printf("%d %d\n",n1,n2);
		}else printf("impossible\n");
	}
	return 0;
}
