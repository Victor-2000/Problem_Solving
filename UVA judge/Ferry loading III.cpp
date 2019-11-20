//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1842

#include <bits/stdc++.h>

using namespace std;

int main() {
	int c;
	cin>>c;
	while(c--){
		int n,t,m,sol[100010];
		queue <pair<int,int> > l,r;
		while(!l.empty())l.pop();
		while(!r.empty())r.pop();
		memset(sol,0,100010);
		cin>>n>>t>>m;
		for(int i=0;i<m;i++){
			pair<int,int> car;
			string b;
			car.second=i;
			cin>>car.first>>b;
			if(b[0]=='l'){
				l.push(car);
			}else{
				r.push(car);
			}	
		}
		int tc=0;
		bool il=1;		
		while(!l.empty() || !r.empty()){
			int ec=numeric_limits<int>::max();
			if(!l.empty()) ec=l.front().first;
			if(!r.empty()) ec=min(ec,r.front().first);
			tc = max(ec,tc);
			int cn=0;
			if(il)
			while(!l.empty() && cn<n && l.front().first<=tc){
				sol[l.front().second]=tc+t;
				l.pop();
				cn++;
			}else while(!r.empty() && cn<n && r.front().first<=tc){
				sol[r.front().second]=tc+t;
				r.pop();
				cn++;
			}
			tc+=t;
			il^=1;	
		} 
		for(int i=0;i<m;i++){
			cout<<sol[i]<<'\n';
		}
		if(c)cout<<'\n';
	}	
	return 0;
}
