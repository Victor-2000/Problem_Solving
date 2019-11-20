//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2454

#include <bits/stdc++.h>

using namespace std;

int V[1000010],S[2][1000010];

int main(){
	int nr=0;
	scanf("%d",&nr);
	while(nr--){
		int a=0,b=0,c=0;
		for(int i=0;i<b;i++)S[0][i]=S[1][i]=0;
		scanf("%d %d %d",&a,&b,&c);
		for(int i=0;i<b;i++)scanf("%d %d",&S[0][i],&S[1][i]);
		for(int i=1;i<=a;i++)V[i]=1;
		int t=1;
		while(c--){
			int v;
			scanf("%d",&v);
			V[t]+=v;
			for(int i=0;i<b;i++)if(V[t]==S[0][i])V[t]=S[1][i];
			if(V[t]>=100){
				V[t]=100;
				for(int i=0;i<c;i++)scanf("%d",&v);
				break;
			}
			t=t%a+1;
		}
		for(int i=1;i<=a;i++){
			printf("Position of player %d is %d.\n",i,V[i]);
			V[i]=1;
		}
	}
	return 0;
}
