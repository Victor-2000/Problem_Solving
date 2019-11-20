//Condition of the problem: https://www.infoarena.ro/problema/rover

#include <bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
 
int c,T[510][510],V[510][510],X[4]={0,1,0,-1},Y[4]={1,0,-1,0},n,g;
 
bool val(int y,int x){
	return (y>0) && (x>0) && (y<=n) && (x<=n) && (!V[y][x]);
}
void Lee(int g){
	deque <pii> d;
	queue <pii> q;
	d.push_front({1,1});
	V[1][1]=1;
	pii dc=d.front();
	while(dc.F!=n || dc.S!=n){
		for(int i=0;i<4;i++){
			if(val(dc.F+Y[i],dc.S+X[i])){
				V[dc.F+Y[i]][dc.S+X[i]]=V[dc.F][dc.S];
				if(T[dc.F+Y[i]][dc.S+X[i]]<g){
					V[dc.F+Y[i]][dc.S+X[i]]++;
					d.push_back({dc.F+Y[i],dc.S+X[i]});
				}else q.push({dc.F+Y[i],dc.S+X[i]});
			}	
		}
		d.pop_front();
		while(!q.empty()){
			d.push_front(q.front());
			q.pop();
		}
		dc=d.front();
	}
}
 
void clear(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			V[i][j]=0;
}
 
int main(){
	ifstream cin("rover.in");
	ofstream cout("rover.out");
	int t;
	cin>>t;
	if(t==1)cin>>n>>g;
	else cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>T[i][j];
		}
	}
	if(t==1){
		Lee(g);
		cout<<V[n][n]-1;
	}else{
		int l=0,r=5000,mid=r/2;
		while(l<r){
			Lee(mid);
			if(V[n][n]>1)r=mid;
			else l=mid+1;
			mid=(l+r)/2;
			clear();
		}
		cout<<mid-1;
	}
	return 0;
}
