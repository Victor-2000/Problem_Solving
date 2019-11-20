//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2628

#include <bits/stdc++.h>

using namespace std;

bool g[4][4],g2[4][4];

int x[4]={1,0,-1,0},y[4]={0,1,0,-1};

bool clear(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			if(g[i][j]) return 0;
		}
	return 1;
}

int main(){
	int n;
	cin>>n;
	char c;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			g[i][j]=g2[i][j]=0; 
	while(n--){
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			cin>>c;
			g[i][j]=c-'0';
		}
		int sol=-1;
		while(!clear()){
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			g2[i][j]=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				for(int k=0;k<4;k++)
				 if(i+x[k]>=0 && i+x[k]<3 && j+y[k]>=0 && j+y[k]<3)
					g2[i][j]=(g2[i][j]+g[i+x[k]][j+y[k]])%2;		
				}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				g[i][j]=g2[i][j];
		sol++;
		//cout<<sol<<'\n';
		//write();
		}
		cout<<sol<<'\n';
	}
	return 0;
}
