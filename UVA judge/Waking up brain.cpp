//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1448

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int v[30],l=1;
bool p[30],a[30];
map <char,int> r;
vi N[30];

void clear(){
	r.clear();
	l=1;
	for(int i=0;i<30;i++){
		p[i]=v[i]=a[i]=0;
		N[i].clear();
	}
}

void makeCell(char c){
	r[(char)c]=l;
	l++;
}

int main(){
	int n;
	while(cin>>n){
		clear();
		int c;
		cin>>c;
		string e;
		cin>>e;
		for(int i=0;i<3;i++){
			makeCell(e[i]);
			a[i+1]=1;
		}
		for(int i=0;i<c;i++){
			cin>>e;
			for(int j=0;j<2;j++){
				if(!r[e[j]]) 
				makeCell(e[j]);
			}
			N[r[e[0]]].push_back(r[e[1]]);
			N[r[e[1]]].push_back(r[e[0]]);
		}
		bool stop = false;
		int t=0;
			while(!stop){
				stop = true;
				for(int i=4;i<=n;i++){
					if(!a[i]){
						for(int j=0;j<N[i].size();j++){
							v[i]+=a[N[i][j]];
						}
						if(v[i]>=3) stop=false;
					}
				}
				for(int i=4;i<=n;i++){
					if(!a[i] && v[i]>=3)a[i]=1;
					else v[i]=0;
				}
				t++;
			}
		t--;
		stop=true;
		for(int i=1;i<=n;i++){
			stop&=a[i];
		}
		if(!stop) cout<<"THIS BRAIN NEVER WAKES UP\n";
		else cout<<"WAKE UP IN, "<<t<<", YEARS\n";
	}
	return 0;
}
