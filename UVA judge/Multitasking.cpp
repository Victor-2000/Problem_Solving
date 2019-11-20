//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3077

#include <bits/stdc++.h>

using namespace std;

bool A[2000100];

int main(){
	int n,m;
	cin>>n>>m;
	while(n!=0||m!=0){
	int st=0,dr=0;
	bool con=0;	
	for(int i=0;i<=2000099;i++)A[i]=0;
	for(int i=0;i<n;i++){
		cin>>st>>dr;
		A[st*2]=1;
		A[dr*2]=1;
		for(int i=st*2+1;i<dr*2 && !con;i++){
			if(A[i]){
				con=1;
				break;
			} 
			A[i]=1;
		}
	}
	for (int i=0;i<m;i++){
		int r=0;
		cin>>st>>dr>>r;
		while(dr<=1000000 && !con){	
			A[st*2]=1;
			A[dr*2]=1;
			for(int i=st*2+1;i<dr*2 && !con;i++){
				if(A[i]){
					con=1;
					break;
				} 
				A[i]=1;
			}
			st+=r;
			dr+=r;
		}
	}	
	if(con) printf("CONFLICT\n");
	else printf("NO CONFLICT\n");
	cin>>n>>m;
	}
}
