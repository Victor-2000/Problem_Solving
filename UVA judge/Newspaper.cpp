//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2315

#include <bits/stdc++.h>

using namespace std;

double A[1000];

int main(){
	int n;
	memset(A,0,1000);
	cin>>n;
	while(n--){
		int nl,nc,val=0;
		cin>>nc;
		memset(A,0,1000);
		while(nc--){
			char c;
			cin>>c>>val;
			A[(int)c]=val;
		}
		cin>>nl;
		string s="";
		cin.ignore();
		double price=0;
		while(nl--){
			getline(cin,s);
			int l=s.size();
			for(int i=0;i<l;i++){
				price+=A[(int)s[i]];
			}	
		}
		printf("%.2f$\n",price/100);
	}
	return 0;
}

