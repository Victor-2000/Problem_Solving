//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=214
#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n,nr,s;
	char c;
	cin>>nr;
	for (int i=0;i<nr;i++){
		//cout<<nr<<'\n';
		cin>>c>>m>>n;		
		switch (c) {
			case'Q':printf("%d\n",min(m,n));
			break;
			case'r':printf("%d\n",min(m,n));
			break;
			case 'k':printf("%d\n",m*n/2+m*n%2);
			break;
			case 'K':printf("%d\n",(m/2+m%2)*(n/2+n%2));
			break;
		}
	}
	return 0;
}
