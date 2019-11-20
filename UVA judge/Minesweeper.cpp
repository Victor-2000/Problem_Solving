//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1130

#include <bits/stdc++.h>

using namespace std;

//ofstream fout("test.out");

int B[150][150];
bool A[150][150];

void bomb(int x,int y){
	int V[4]={0,1,-1};
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			B[x+V[i]][y+V[j]]++;
		}
}

void clear(){
	for(int i=0;i<=150;i++)
		for(int j=0;j<=150;j++){
			B[i][j]=0;
			A[i][j]=0;
		}
}


int main(){
	int m=0,n=0,f=0;//INITIALIZEAZA!!! Din cauza asta am stat 15 min sa fac debugging
	char c;
	scanf("%d %d",&n,&m);
	while(m!=0 && n!=0){
	f++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&c);
			while(c!='*' && c!='.')
				scanf("%c",&c);
			if(c=='*'){
				A[i][j]=1;
				bomb(i,j);
			}else A[i][j]=0;
		}
	}
	printf("Field #%d:\n",f);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
				if(A[i][j]) printf("*");
				else printf("%d",B[i][j]);
		}
		printf("\n");
	}
	clear();
	scanf("%d %d",&n,&m);
	if(m!=0 && n!=0) printf("\n");
	}
	return 0;
}
