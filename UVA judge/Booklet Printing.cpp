//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=578

#include <bits/stdc++.h>

using namespace std;

bool P[110];

int last(int n){
	for(int i=n;i>0;i--){
		if(!P[i]) return i;
	}
	return 0;
}

int main(){
	int np;
	while(scanf("%d",&np)==1){
		if(np==0)break;
		int bn=np%4,sn=0;
		if(bn==3)bn=1;
		else if(bn==1) bn=3;
		for(int i=1;i<=100;i++)P[i]=0;
		printf("Printing order for %d pages:\n",np);
		for(int i=1;i<=np;i++){
			if(P[i]) break;
			if((sn+1)%2){
				if(bn>0){
					P[i]=1;
					printf("Sheet %d, front: Blank, %d\n",sn/2+1,i);
					bn--;
				}else{
					P[i]=1;
					int l=last(np);
					if(!l)break;
					printf("Sheet %d, front: %d, %d\n",sn/2+1,l,i);
					P[l]=1;
				} 
			}else{
				if(bn>0){
					P[i]=1;
					printf("Sheet %d, back : %d, Blank\n",sn/2+1,i);
					bn--;
				}else{
					P[i]=1;
					int l=last(np);
					if(!l)break;
					printf("Sheet %d, back : %d, %d\n",sn/2+1,i,l);
					P[l]=1;
				} 
			}
			sn++;
		}
	}
	return 0;
}
