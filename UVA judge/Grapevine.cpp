//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3344

#include <bits/stdc++.h>

using namespace std;

int m,n,q,H[510][510];

int bin(int r, int l){
	int hi=m,lo=1,ind=-1;
	while(hi>lo+1){
		int mid=(hi+lo)/2;
		if(H[r][mid]>=l){
			hi=mid;
			ind=mid;
		}else{
			lo=mid;
		}
	}
	if(H[r][lo]>=l)ind=lo;
	else if(H[r][hi]>=l)ind=hi;
	return ind;
}

int dbin(int ic,int d, int r){
	int hi=min(m-d,n-ic),lo=0,ind=-1;
	while(hi>lo+1){
		int mid=(hi+lo)/2;
		if(H[ic+mid][d+mid]<=r){
			lo=mid;
			ind=mid;
		}else{
			hi=mid;
		}
	}
	if(ind=-1 && H[ic+hi][d+hi]<=r)ind=hi;
	else if(H[ic+lo][d+lo]<=r)ind=lo;
	return ind;
}

int main(){
	cin>>n>>m;
	while(n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>H[i][j];
			}
		}
		cin>>q;
		int l,u;
		while(q--){
			cin>>l>>u;
			int cb=0,sol=-1;
			for(int i=1;i<=n;i++){
				cb=bin(i,l);
				if(cb!=-1 && H[i][cb]<=u)sol=max(sol,dbin(i,cb,u));
			}
			cout<<sol+1<<'\n';
		}
		cin>>n>>m;
		cout<<"-\n";
	}
	return 0;
}
