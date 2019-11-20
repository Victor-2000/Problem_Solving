//Condition of the problem: https://www.infoarena.ro/problema/tetris

#include <bits/stdc++.h>
#define PMAX 3000000
#define NMAX 2005
using namespace std;
 
int c[3][PMAX],s,d[NMAX],n,k;
bool f[NMAX][NMAX];
 
void dp(){
	f[0][0]=1;
	c[0][0]=c[1][0]=0;
	c[2][0]=-1;
	s=1;
	for(int i=0;i<n;i++){
		int cs=s;
		for(int j=s-1;j>=0 && c[2][j]==i-1;j--){
			int x=c[0][j],y=c[1][j];
			if(!f[x][y+d[i]] && x<=n && y+d[i]<=n){
				c[0][cs]=x;
				c[1][cs]=y+d[i];
				c[2][cs++]=i;
				f[x][y+d[i]]=1;
			}
			if(!f[x+d[i]][y] && y<=n && x+d[i]<=n){
				c[0][cs]=x+d[i];
				c[1][cs]=y;
				c[2][cs++]=i;
				f[x+d[i]][y]=1;
			}
		}
		s=cs;
	}
}
 
int main(){
	ifstream cin("tetris.in");
	ofstream cout("tetris.out");
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>d[i];
	}
	dp();
	cout<<s;	
	return 0;
}
