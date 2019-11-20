//Condition of the problem: https://www.infoarena.ro/problema/alpin

#include <bits/stdc++.h>
#define pii pair <int,int>
#define F first
#define S second
#define vii vector <pii>
#define MAXN 1030
#define MAX 1001000
using namespace std;
 
int T[MAXN][MAXN],n,m=0,D[MAXN][MAXN];
char X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
vii ts;
vector <int> s;
 
bool eval(int y,int x){
	return (y<=n && x<=n && y>0 && x>0);
}
 
int dp(int y, int x){
	D[y][x]=1;
	for(int i=0;i<4;i++){
		if(eval(y+Y[i],x+X[i]) && T[y+Y[i]][x+X[i]]>T[y][x])
		 if(!D[y+Y[i]][x+X[i]]){
		 	D[y][x]=max(D[y][x],dp(y+Y[i],x+X[i])+1);
		 }else{
		 	D[y][x]=max(D[y][x],D[y+Y[i]][x+X[i]]+1);
		 }
	}
	return D[y][x];
}
 
int main(){
	ifstream cin("alpin.in");
	ofstream cout("alpin.out");
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>T[i][j];
			pii c;
			c.F=i;
			c.S=j;
			ts.push_back(c);
			D[i][j]=0;
		}
	}
	int l=ts.size(),ym,xm;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!D[i][j])dp(i,j);
			if(m<D[i][j]){
				m=D[i][j];
				ym=i;
				xm=j;
			}
		}
	}
	cout<<m<<'\n';
	bool change=true;
	while(m){
		cout<<ym<<' '<<xm<<'\n';
		for(int i=0;i<4;i++){
			if(eval(ym+Y[i],xm+X[i]) && D[ym+Y[i]][xm+X[i]]==m-1 && T[ym+Y[i]][xm+X[i]]>T[ym][xm]){
				ym+=Y[i];
				xm+=X[i];
				break;
			}
		}
		m--;
	}
	return 0;
}
