//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1384

#include <bits/stdc++.h>

using namespace std;

int M[3][101][101],r,c,n,t;

bool Dwin(int a,int b){
	return ((a==0 && b==1)||(a==1 && b==2)||(a==2 && b==0));
}

void control(int x,int y,int o){
	int nx=(o+1)%2;
	if(y!=0 && (Dwin(M[o][x][y-1],M[o][x][y])||(M[o][x][y-1]==2 && M[o][x][y]==0)))M[nx][x][y]=M[o][x][y-1];
	else if(x!=0 && (Dwin(M[o][x-1][y],M[o][x][y])||(M[o][x-1][y]==2 && M[o][x][y]==0)))M[nx][x][y]=M[o][x-1][y];
	else if(x!=r-1 && (Dwin(M[o][x+1][y],M[o][x][y])||(M[o][x+1][y]==2 && M[o][x][y]==0)))M[nx][x][y]=M[o][x+1][y];
	else if(y!=c-1 && (Dwin(M[o][x][y+1],M[o][x][y])||(M[o][x][y+1]==2 && M[o][x][y]==0)))M[nx][x][y]=M[o][x][y+1];
	else M[nx][x][y]=M[o][x][y];
}

void clear(){
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			M[1][i][j]=M[0][i][j]=3;
}
//R-0 S-1 P-2
char D[4]={'R','S','P'};

int main(){
	scanf("%d",&t);
	char ch;
	while(t--){
		clear();
		scanf("%d %d %d",&r,&c,&n);
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			scanf("%c",&ch);
			if(ch=='\n')scanf("%c",&ch);
			switch(ch){
				case 'R':M[1][i][j]=0;break;
				case 'S':M[1][i][j]=1;break;
				case 'P':M[1][i][j]=2;break;
			}
		}
		int o=1;
		while(n--){
			for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				control(i,j,o);
			o=(o+1)%2;		
		}
		//o=(o+1)%2;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%c",D[M[o][i][j]]);
			}
			printf("\n");
		}	
		if(t)printf("\n");
	}
	return 0;
}
