//Condition of the problem: https://www.infoarena.ro/problema/antivirus

#include <bits/stdc++.h>
#define NMAX 2010
#define INF 1ll<<60
#define ll long long
using namespace std;
 
int A[NMAX],n,k,t;
ll DP[NMAX][NMAX],P[NMAX];
 
ll dp(){
	//INIT
	for(int i=0;i<=n;i++){
		DP[i][0]=0;
	}
	//CORE		
	int last=0;
	for(int i=1;i<=n;i++){
		if(A[i]>0){
				if(last){
					for(int j=k;j>0;j--){
						DP[i][j]=DP[i-1][j];
						if(j-(i-last)>=0 && DP[last][j-(i-last)]!=INF){
							DP[i][j]=min(DP[i][j],DP[last][j-(i-last)]+P[i]-P[last]);
						}
					}
				}
		}else{
			for(int j=k;j>0;j--){
				DP[i][j]=DP[i-1][j];
				for(int h=i-1;h>=last;h--){
					if(j-(i-(h+1))>=0 && DP[h][j-(i-(h+1))]!=INF){
						DP[i][j]=min(DP[i][j],P[i]-P[h]+DP[h][j-(i-(h+1))]);
					}
				}
			}
			last=i;
		}
	}
	return DP[n][k];
}
 
int main(){
	ifstream cin("antivirus.in");
	ofstream cout("antivirus.out");
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				DP[i][j]=INF;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>A[i];
			P[i]=A[i];
			if(!A[i])k--;
			P[i]+=P[i-1];
		}
		cout<<dp()<<'\n';	
	}
	return 0;
}
