//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2595

# include <bits/stdc++.h>

using namespace std;

int a,n,b,h,w,s=-1;

int main(){
	while(scanf("%d ",&n)!=EOF){
	scanf("%d %d %d",&b,&h,&w);
	for(int i=0;i<h;i++){
		int p;
		scanf("%d",&p);
		for(int j=0;j<w;j++){
			scanf("%d",&a);
			if (a>=n && (s>n*p||s==-1) && b>n*p) s=n*p;
		}
	}
	if(s!=-1)
		printf("%d\n",s);
		else printf("stay home\n");
	s=-1;
	}
	return 0;
}
