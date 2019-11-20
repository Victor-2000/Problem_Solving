//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=465
#include <bits/stdc++.h>

using namespace std;

int n,p[]={2,3,5,7,11,13,17,19,23,29,31},A[16];
bool isA[16];

bool isp(int a){
	for(int i=0;i<n;i++)
	if(p[i]==a) return true;
	return false;
}

void bk(int k){
	if(k==n && isp(A[k-1]+1)){
		for(int i=0;i<k-1;i++){
			cout<<A[i]<<' ';
		}
		cout<<A[k-1]<<'\n';
	}
	for(int i=2;i<=n;i++){
		if(!isA[i] && isp(i+A[k-1])){
			isA[i]=1;
			A[k]=i;
			bk(k+1);
			isA[i]=0;
		}
	}
}

int main(){
	int t=1;
	while(cin>>n){
		if(t!=1)cout<<'\n';
		memset(isA,0,n);
		A[0]=1;
		printf("Case %d:\n",t++);
		bk(1);
	}
}
