//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2619

#include <bits/stdc++.h>

using namespace std;

int S[1000010];

int main(){
	map <int,int> sf;
	int c;
	cin>>c;
	while(c--){
		sf.clear();
		int n,solc=0,sol=0;
		cin>>n;
		memset(S,0,n);
		for(int i=1;i<=n;i++)cin>>S[i];
		int j=9;
		if(j==9)j=10;
		for(int i=1;i<=n;i++){
			//cout<<sf[S[i]]<<'\n';
			if(sf[S[i]]!=0){
				i=sf[S[i]];
				sf.clear();
				sol=max(sol,solc);
				solc=0;
			}else{
				sf[S[i]]=i;
				solc++;
			}
		}
		sol=max(sol,solc);
		cout<<sol<<'\n';
	}
	return 0;
}
