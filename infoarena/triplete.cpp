//Condition of the problem: https://www.infoarena.ro/problema/triplete

#include <bits/stdc++.h>
 
using namespace std;
 
#define NMAX 4100 
#define MMAX 66000
 
ifstream fin("triplete.in");
ofstream fout("triplete.out");
 
vector <int> la[NMAX];
int n,m,sol=0,x=0;
bool M[NMAX]; 
 
void DFS(int k,int i,int parent){
	int l=la[i].size();
	if(k<2){
		for(int j=0;j<l;j++){
			if(M[la[i][j]] && la[i][j]!=parent)DFS(k+1,la[i][j],i);
		}	
	}else{
		for(int j=0;j<l;j++){
			if(la[i][j]==x){
				sol++;
				return;
			}
		}
	}
}
 
 
int main(){
	fin>>n>>m;
	for(int i=0;i<n;i++)la[i].clear();
	for(int i=0;i<m;i++){
		int a,b;
		fin>>a>>b;
		la[a].push_back(b);
		la[b].push_back(a);
	}	
	
	for(int i=1;i<=n;i++)
	{ 
		x=i;
		for(int j=0;j<=n;j++)M[j]=0;
		for(int j=0;j<la[i].size();j++)M[la[i][j]]=1;
		DFS(0,i,-1);
	}
	fout<<sol/6;
	return 0;
}
