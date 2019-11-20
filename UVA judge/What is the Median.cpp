//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1048

#include <bits/stdc++.h>

using namespace std;

int A[10000];

int main(){
	int n=0;
	while(cin>>A[n]){
		n++;
		sort(A,A+n);
		cout<<(A[(n-1)/2]+A[(n-1)/2+(n-1)%2])/2<<'\n';
	}
	return 0;
}
