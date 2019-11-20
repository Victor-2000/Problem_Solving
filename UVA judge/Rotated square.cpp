//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1796

#include <bits/stdc++.h>

using namespace std;

char A[10000][10000],Am[10000][10000],B[10000][10000];
int n,m;

void rotate(){
	for(int i=0;i<=(n-1)/2;i++){
		for(int j=i;j<n-i;j++){
			B[(n-1)-j][i]=A[i][j];
			B[(n-1)-i][j]=A[j][i];
			B[(n-1)-j][(n-1)-i]=A[(n-1)-i][j];
			B[i][j]=A[j][(n-1)-i];
		}
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		A[i][j]=B[i][j];
}

int main(){
	cin>>n>>m;
	while(n&&m){
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				cin>>Am[i][j];
		for(int i=0;i<4;i++){
			int sol=0;
			for(int j=0;j<=n-m;j++)
				for(int k=0;k<=n-m;k++){
					bool isEqual=true;
					for(int l=0;l<m && isEqual;l++){
						for(int o=0;o<m && isEqual;o++){
							if(Am[l][o]!=A[j+l][k+o])isEqual=false;
						}
					}
					if(isEqual)sol++;
				}
			cout<<sol;
			if(i<3) cout<<' ';
			else cout<<'\n';
			rotate();
		}
		cin>>n>>m;	
	}
	return 0;
}
