//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1754

#include <bits/stdc++.h>

using namespace std;

int n,C[6][6];

void afisare(){
	cout<<'\n';
	for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)
				cout<<C[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}

bool check(int x,int y){
	int v=0,h=0,d1=0,d2=0;
	for(int i=0;i<5;i++){
		if(!C[x][i])h++;
		if(!C[i][y])v++;
		if(!C[i][i])d1++;
		if(!C[4-i][i])d2++;
	}
	return (v==5||h==5||d1==5||d2==5);
}

void clear(){
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
		C[i][j]=0;
}

int main(){
	scanf("%d",&n);
	while(n--){
		//Curatim cardul
		clear();
		//Citirea cardului
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				if(!(i==2 && j==2))
				scanf("%d",&C[i][j]);
		int call;
		bool c=false;
		//Citirea numerelor extrase
		for(int i=0;i<75;i++){
			scanf("%d",&call);
			for(int j=0;j<5;j++){
				if(c)break;
				for(int k=0;k<5;k++){
					if(call==C[j][k]){
						C[j][k]=0;
						//afisare();
						if(check(j,k)){	
							c=true;
							printf("BINGO after %d numbers announced\n",i+1);
							break;
						} 
					}
				}	
			}
		}
	}
	return 0;
}
