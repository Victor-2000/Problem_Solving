//Condition of the problem: https://www.infoarena.ro/problema/rj

#include<bits/stdc++.h>
#define pii  pair <int,int>
#define F first 
#define S second
using namespace std;
 
int LJ[105][105],LR[105][105],n,m,rx,ry,jx,jy,s,X[8]={-1,-1,-1,0,0,1,1,1},Y[8]={-1,0,1,-1,1,-1,0,1};
string T[105];
 
bool val(int y,int x){
	return (x>0) && (y>0) && (x<=m) && (y<=n) && (T[y][x]!='X');
}
 
void write(int A[105][105]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<A[i][j]<<' ';
		}
		cout<<'\n';
	}
}
 
void BFS(){
	queue <pii> R,J;
	//Initializam coada
	R.push({ry,rx});
	J.push({jy,jx});
	LJ[jy][jx]=LR[ry][rx]=1;
	pii cj=J.front(),cr=R.front();
	while(!R.empty() && !J.empty()){
		if(LR[cr.F][cr.S]<=LJ[cj.F][cj.S]){
			for(int i=0;i<8;i++){
				if(!LR[cr.F+Y[i]][cr.S+X[i]] && val(cr.F+Y[i],cr.S+X[i])){
					R.push({cr.F+Y[i],cr.S+X[i]});
					LR[cr.F+Y[i]][cr.S+X[i]]=LR[cr.F][cr.S]+1;
				}
			}
			R.pop();
			cr=R.front();
		}
		if(LJ[cj.F][cj.S]<=LR[cr.F][cr.S]){
			for(int i=0;i<8;i++){
			if(!LJ[cj.F+Y[i]][cj.S+X[i]] && val(cj.F+Y[i],cj.S+X[i])){
					J.push({cj.F+Y[i],cj.S+X[i]});
					LJ[cj.F+Y[i]][cj.S+X[i]]=LJ[cj.F][cj.S]+1;
				}
			}
			J.pop();
			cj=J.front();
		}		
	}
}
 
int main(){
	ifstream cin("rj.in");
	ofstream cout("rj.out");
	cin>>n>>m;
	getline(cin,T[0]);
	for(int i=1;i<=n;i++){
		getline(cin,T[i]);
		T[i]='&'+T[i];
		for(int j=1;j<=m;j++){
			if(T[i][j]=='R'){
				ry=i;
				rx=j;
			}else if(T[i][j]=='J'){
				jy=i;
				jx=j;
			}
		}
	}
	BFS();
	int mis=1000,ys,xs;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(LJ[i][j] && LR[i][j] && LJ[i][j] == LR[i][j] && mis>(LJ[i][j]+LR[i][j])){
				mis=LJ[i][j]+LR[i][j];
				xs=i;
				ys=j;
				s=max(LJ[i][j],LR[i][j]);
			}
		}
	}
	cout<<s<<' '<<xs<<' '<<ys;
	return 0;
}
