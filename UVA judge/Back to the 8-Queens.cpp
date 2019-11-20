//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2026

#include <bits/stdc++.h>

using namespace std;

int Ai[9],A[9],t=0,sol;

bool valid(int v,int k){
	for(int i=0;i<k;i++){
		if(A[i]==v ||abs(A[i]-v)==abs(i-k))return 0; 
	}
	return 1;
}

void bk(int k){
	if(k>=8){
		int sum=0;
		for(int i=0;i<8;i++){
			if(A[i]!=Ai[i])sum++;
		}
		sol=min(sol,sum);
		return;
	}
	for(int i=1;i<9;i++){
		if(valid(i,k)){
			A[k]=i;
			bk(k+1);
		}
	}
}
int main(){
	while(cin>>Ai[0]){
		for(int i=1;i<8;i++){
			cin>>Ai[i];
		}
		sol=1000000;
		bk(0);
		printf("Case %d: %d\n",++t,sol);
	}
	return 0;
}
