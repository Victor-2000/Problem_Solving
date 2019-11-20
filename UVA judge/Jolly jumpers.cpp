//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979

#include <bits/stdc++.h>

using namespace std;

bool A[3000];

int main(){
	int n;
	memset(A,0,3000);
	while(cin>>n){
		int c=0,ct=0;
		memset(A,0,n);
		for(int i=0;i<n;i++){
			if(i!=0){
				ct=c;
				cin>>c;
				A[abs(c-ct)]=1;
			}else cin>>c;
		}
		int i=1;
		while(A[i] && i<n){
			i++;
		}
		if(i==n)printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
