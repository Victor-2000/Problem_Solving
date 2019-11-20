//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3142

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

vi Nr[1000010];

int main(){
	int m,n;
	while(cin>>m){
		cin>>n;
		for(int i=1;i<=m;i++){
			int c;
			cin>>c;
			Nr[c].push_back(i);
		}
		for(int j=0;j<n;j++){
			int k,v;
			cin>>k>>v;
			if(Nr[v].size()>=k)
			cout<<Nr[v][k-1]<<'\n';
			else cout<<0<<'\n';
		}
		for(int i=1;i<=m;i++){
			Nr[i].clear();
		}
	}
	return 0;
}
