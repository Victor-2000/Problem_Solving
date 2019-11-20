//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057

#include <bits/stdc++.h>

using namespace std;

int rd[4]={1,-1,1,-1},cd[4]={1,1,-1,-1},r,c,m,n,w,par,im,A[110][110];

bool valid(int y, int x){
	return (y>=0 && y<r && x>=0 && x<c);
}

void DFS(int rc,int cc){
	int k=0;
	A[rc][cc]=-1;
	if(!n || !m){
		for(int i=0;i<2;i++){
			if(valid(rc+m*rd[i],cc+n*cd[i+1])){
				if(A[rc+m*rd[i]][cc+n*cd[i+1]]!=1)k++;
				if(A[rc+m*rd[i]][cc+n*cd[i+1]]==0){
					DFS(rc+m*rd[i],cc+n*cd[i+1]);
				}
			}
			if(valid(rc+n*rd[i],cc+m*cd[i+1])){
				if(A[rc+n*rd[i]][cc+m*cd[i+1]]!=1)k++;
				if(A[rc+n*rd[i]][cc+m*cd[i+1]]==0){
					DFS(rc+n*rd[i],cc+m*cd[i+1]);
				}
			}
		}
	}
	else for(int i=0;i<4;i++){
		if(valid(rc+m*rd[i],cc+n*cd[i])){
			if(A[rc+m*rd[i]][cc+n*cd[i]]!=1)k++;
			if(A[rc+m*rd[i]][cc+n*cd[i]]==0){
				DFS(rc+m*rd[i],cc+n*cd[i]);
			}
		}
		if(m!=n)
		if(valid(rc+n*rd[i],cc+m*cd[i])){
			if(A[rc+n*rd[i]][cc+m*cd[i]]!=1)k++;
			if(A[rc+n*rd[i]][cc+m*cd[i]]==0){
				DFS(rc+n*rd[i],cc+m*cd[i]);
			}
		}
	}
	if(k%2) im++;
	else par++;
}

int main(){
	int T;
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>r>>c>>m>>n>>w;
		memset(A, 0, sizeof A);
		par=im=0;
		for(int i=0;i<w;i++){
			int a,b;
			cin>>a>>b;
			A[a][b]=1;
		}
		DFS(0,0);
		cout<<"Case "<<k<<": "<<par<<' '<<im<<'\n';
	}
	return 0;
}
