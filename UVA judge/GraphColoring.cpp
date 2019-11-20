//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=129
#include <bits/stdc++.h>

using namespace std;

vector <int> l[101],ps;
bool s[101];
int m,n,k,sol;
	
bool av(int cn){
	for(int i=0;i<l[cn].size();i++){
		if(cn>l[cn][i] && s[l[cn][i]]==s[cn]) return false;
	}
	return true;
}	
	
void bk(int k){
	if(k==n+1){
		int nc=0;
		for(int i=1;i<=n;i++){
			if(s[i]){
				nc++;
			}
		}
		if(sol<nc){
			sol=nc;
			ps.clear();
			for(int i=1;i<=n;i++){
				if(s[i]){
					ps.push_back(i);
				}
			}
		}
		return;
	}
	s[k]=1;
	if(av(k))bk(k+1);
	s[k]=0;	
	bk(k+1);
}

void clear(){
	memset(s,0,n+1);
	sol=0;
	for(int i=1;i<=n;i++){
		l[i].clear();
	}
}

int main(){
	cin>>m;
	while(m--){
		cin>>n>>k;
		clear();
		for(int i=0;i<k;i++){
			int a,b;
			cin>>a>>b;
			l[a].push_back(b);
			l[b].push_back(a);
		}
		s[1]=0;
		bk(1);
		s[1]=1;
		bk(1);
		cout<<sol<<'\n';
		for(int i=0;i<sol-1;i++){
			cout<<ps[i]<<' ';
		}
		cout<<ps[sol-1]<<'\n';
	}
	return 0;
}
