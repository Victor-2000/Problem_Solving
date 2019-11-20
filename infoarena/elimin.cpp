//Condition of the problem: https://www.infoarena.ro/problema/elimin

#include <bits/stdc++.h>
 
#define NMAX 1001
 
typedef long long ll;
 
using namespace std;
 
ifstream fin("elimin.in");
ofstream fout("elimin.out");
  
int A[NMAX][NMAX],R[NMAX],I[NMAX],C[NMAX],m,n,r,c,s=0;
   
void solve(int k){
 for(int i = I[k-1]+1;i<=m;i++){
	I[k]=i;
	if (k<=r){
	  if (k==r){
			int sc=0;
			/*for(int i=1;i<=n;i++){
				C[i]=0;
			}*/
		 	for(int i = 1;i<=r;i++)
    		  for(int j = 1;j<=n;j++){
    		  if(i==1) C[j]=0;
		 	  C[j]+=A[I[i]][j];
		  	}
		 	sort(C+1,C+1+n); 
	  	 	for(int i=n;i>c;i--)  
	     	   sc+=C[i];
		 	if(sc>s) s=sc;
			} else solve(k+1); 
		}
	}
}
 
int main(){
    fin>>m>>n>>r>>c; 
    I[0]=0;
	if(m<=n){
		for (int i = 1;i<=m;i++){
       		for(int j = 1;j<=n;j++){
       		     fin>>A[i][j];  
       		}
    	}
	}else{
		for (int i = 1;i<=m;i++){
       		for(int j = 1;j<=n;j++){
       		     fin>>A[j][i];  
       		}
    	}
    swap(m,n);swap(r,c);
	}	
    r=m-r;
	solve(1);
    fout<<s;
    return 0;
}
