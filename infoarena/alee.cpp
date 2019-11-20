//Condition of the problem: https://www.infoarena.ro/problema/alee

#include <bits/stdc++.h>

#define NMAX 180
#define ii pair<int,int>
#define F first
#define S second

using namespace std;

int alee[NMAX][NMAX];
int n,m,pathChoice[5]={-1,0,1,0,-1};
queue <ii> q;
ii	startGate, endGate;

ifstream fin ("alee.in");
ofstream fout ("alee.out");

bool isValid(int x, int y){
	return (x > 0) && (x <= n) && (y > 0) && (y <= n) && (alee[x][y] == 0);
}

int lee(ii startGate, ii endGate){
	q.push(startGate);
	alee[startGate.F][startGate.S] = 1;
	do{
		for(int i=0;i<4;i++){
			ii potentialPath;
			potentialPath = {q.front().F + pathChoice[i], q.front().S + pathChoice[i+1]};
			if(isValid(q.front().F + pathChoice[i], q.front().S + pathChoice[i+1])){
				q.push(potentialPath);
				alee[potentialPath.F][potentialPath.S] = alee[q.front().F][q.front().S] + 1;
			}
			if(potentialPath == endGate) return alee[potentialPath.F][potentialPath.S];
		}
		q.pop();
	}while(q.front() != endGate);
	return alee[q.front().F][q.front().S];
}

int main(){
	fin>>n;
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			alee[i][j] = 0;
		}
	}
	fin>>m;
	for(int i=0;i<m;i++){
		int x,y;
		fin>>y>>x;
		alee[x][y]=-1;
	}
	fin>>startGate.S>>startGate.F>>endGate.S>>endGate.F;
	fout<<lee(startGate, endGate);
	return 0;
}


