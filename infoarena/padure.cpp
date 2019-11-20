//Condition of the problem: https://www.infoarena.ro/problema/padure

#include <bits/stdc++.h>
#define NMAX 1010
#define pii pair <int,int>
#define qii queue <pii>
#define F first
#define S second
using namespace std;
 
struct iii{
	int y,x,v;
};
 
int T[NMAX][NMAX],D[NMAX][NMAX],n,m,pl,pc,cl,cc,X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
 
queue <iii> qv;
 
bool eval(int y, int x){
	return(y>0 && x>0 && y<=n && x<=m);
}
 
void ff(int ys,int xs,int cd){
	qii q;
	q.push({ys,xs});
	int c=T[ys][xs];
	D[ys][xs]=cd;
	while(!q.empty()){
		pii cp=q.front();
		for(int i=0;i<4;i++){
			if(eval(cp.F+Y[i],cp.S+X[i]) && D[cp.F+Y[i]][cp.S+X[i]]==-1){
			 if(T[cp.F+Y[i]][cp.S+X[i]]==c){
			 	q.push({cp.F+Y[i],cp.S+X[i]});
			 	D[cp.F+Y[i]][cp.S+X[i]]=cd;
			 }else{	
				 		iii c;
				 		c.y=cp.F+Y[i];
				 		c.x=cp.S+X[i];
				 		c.v=cd+1;
					 	qv.push(c);
			 	} 	
			}
		}
		q.pop();
	}
}
 
void solve(){
	while(D[cl][cc]==-1){
		iii c=qv.front();
		if(D[c.y][c.x]==-1)ff(c.y,c.x,c.v);
		qv.pop();
	}
}
 
int main(){
	ifstream cin("padure.in");
	ofstream cout("padure.out");
	cin>>n>>m>>pl>>pc>>cl>>cc;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>T[i][j];
			D[i][j]=-1;
		}
	}
	iii c;
	c.y=pl;
	c.x=pc;
	c.v=0;
	qv.push(c);
	solve();
	cout<<D[cl][cc];
	return 0;
}
