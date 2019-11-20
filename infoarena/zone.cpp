//Condition of the problem: https://www.infoarena.ro/problema/zone

#include <bits/stdc++.h>
 
using namespace std;
 
int Z[10],n,l1,l2,c1,c2,T[515][515];
long long S[10],dp[515][515];
bool A[10],stop=false;
 
ifstream fin("zone.in");
ofstream fout("zone.out");
 
long long sum(int sl,int sc,int fl,int fc){
	long long s=dp[fl][fc];
	if(sl)s-=dp[sl-1][fc];
	if(sc)s-=dp[fl][sc-1];
	if(sl && sc)s+=dp[sl-1][sc-1];
	return s;
}
 
bool ctr(long long s,int z){
	for(int i=1;i<=9;i++){
		if(!A[i] && s==S[i]){
			A[i]=1;
			Z[z]=i;
			return true;
		}
	}
	return false;
}
 
void bkc(int k);
 
void bkl(int k){
	if(!k){
		for(int i=0;i<n-2;i++){
			l1=i;
			bkc(k);
			if(stop) return;
		}
	}else{
		for(int i=l1+1;i<n-1;i++){
			l2=i;
			long long s=sum(l1+1,0,l2,c1);//4
			if(ctr(s,4)){
				s=sum(l2+1,0,n-1,c1);
				if(ctr(s,7)){
					bkc(k);
					if(stop)return;
				}
				A[Z[7]]=0;
			}
			A[Z[4]]=0;
		}
	}
}
 
void bkc(int k){
	if(!k){
		for(int i=0;i<n-2;i++){
			c1=i;
			long long s1=sum(0,0,l1,c1);//1
			if(ctr(s1,1)){
				bkl(k+1);
				if(!stop)A[Z[1]]=0;
				else return;
			}
		}
	}else{
		for(int i=c1+1;i<n-1;i++){
			c2=i;
			long long s=sum(0,c1+1,l1,c2);//2
			if(ctr(s,2)){
				s=sum(0,c2+1,l1,n-1);//3
				if(ctr(s,3)){
					s=sum(l1+1,c1+1,l2,c2);//5
					if(ctr(s,5)){
						s=sum(l1+1,c2+1,l2,n-1);//6
						if(ctr(s,6)){
							s=sum(l2+1,c1+1,n-1,c2);//8
							if(ctr(s,8)){
								s=sum(l2+1,c2+1,n-1,n-1);//9
								if(ctr(s,9)){
									stop=true;
									return;
								}
								A[Z[8]]=0;
							}
							A[Z[6]]=0;
						}
						A[Z[5]]=0;
					}
					A[Z[3]]=0;
				}
				A[Z[2]]=0;
			}
		}
	}
}
 
void DP(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i||j){
				if(j!=0)dp[i][j]+=dp[i][j-1];
				if(i!=0)dp[i][j]+=dp[i-1][j];
				if(i&&j)dp[i][j]-=dp[i-1][j-1];
			}
		}
	}
}
 
int main(){
	fin>>n;
	for(int i=1;i<=9;i++){
		Z[i]=A[i]=0;
		fin>>S[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin>>T[i][j];
			dp[i][j]=T[i][j];
		}
	}
	DP();
	bkl(0);
	fout<<l1+1<<' '<<l2+1<<' '<<c1+1<<' '<<c2+1;
	return 0;
}
