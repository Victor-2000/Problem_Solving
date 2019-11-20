//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3678

#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

struct car{
	string s;
	int lo,hi;
};

car C[MAX];
bitset <1000000> b;

int main(){
	int t;
	cin>>t;
	while(t--){
		int p,m,max=0,n,nr=0;
		string sol;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>C[i].s>>C[i].lo>>C[i].hi;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>p;
			nr=0;
			bool un=0;
			for(int j=0;j<n;j++){
				if(p>=C[j].lo && p<=C[j].hi){
					if(!nr){
						sol=C[j].s;
						nr++;
					}else{
						printf("UNDETERMINED\n");
						un=1;
						break;
					}
				}
			}
			if(!un){
				if(!nr)printf("UNDETERMINED\n");
				else cout<<sol<<'\n';
			}
		}
		if(t)cout<<'\n';
	}
	return 0;
}
