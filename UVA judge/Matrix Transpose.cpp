//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1836

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector <ii> vii;

vii M[10100];

int main(){
	int m,n;
	int rw[10100];
	while(cin>>m){
		cin>>n;
		for(int i=0;i<m;i++){
			int nc,vc;
			cin>>nc;
			for(int j=0;j<nc;j++){
				cin>>rw[j];
				rw[j]--;
			}
			ii cr;
			cr.first=i;
			for(int j=0;j<nc;j++){
				cin>>vc;
				cr.second=vc;
				M[rw[j]].push_back(cr);
				//rw[j]=0;
			}
		}
		printf("%d %d\n",n,m);
		for(int i=0;i<n;i++){
			int l=M[i].size();
			cout<<l;
			for(int j=0;j<l;j++){
				cout<<' '<<M[i][j].first+1;
			}
			cout<<'\n';
			for(int j=0;j<l;j++){
				cout<<M[i][j].second;
				if(j<l-1)cout<<' ';
			}
			cout<<'\n';
			M[i].clear();
		}
	}
	return 0;
}
