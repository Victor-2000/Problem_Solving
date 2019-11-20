//Condition of the problem: https://www.infoarena.ro/problema/coins
#include <bits/stdc++.h>
#define NMAX 1<<22+1
 
using namespace std;
 
bool A[NMAX],C[22];
int n;
 
void rez(){
	for(int p=1;p<NMAX;p++){
		if(!A[p]){
			bool ok=0;
			int pre=-1;
			for(int i=1;i<=p;i<<=1){
				if(i&p){
					if(pre!=-1){
						if(!A[p+pre-i]){
							ok=1;
							break;
						}
					}
				} else pre=i;
			}
			A[p]=ok;
		}
	}
}
 
int main(){
	ifstream cin("coins.in");
	ofstream cout("coins.out");
	//precalculare
	for(int i=0;i<=22;i++){
		A[(1<<i)-1]=true;
	}
	rez();
	cin>>n;
	int sol=0;
	for(int i=0;i<n;i++){
		int s=0,t=0;
		for(int j=0;j<=21;j++)cin>>C[j];
		for(int j=21;j>=0;j--){
		 	if(C[j]!=1){
		 		while(C[j]!=1)j--;
		 		j++;	
			}
		 	s|=(C[j]<<j);
		 	if(C[j])t++;
		}
		if(A[s])sol+=t;
	}
	cout<<sol;
	return 0;
}
