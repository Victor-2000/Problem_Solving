//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895

#include <bits/stdc++.h>

using namespace std;

int main(){
	priority_queue <int> q;
	int n,sol;
	cin>>n;
	while(n!=0){
		sol=0;
		int c,s,t1;
		for(int i=0;i<n;i++){
			cin>>c;
			q.push(-c);
		}
		while(!q.empty()){
			s=-q.top();
			q.pop();
			s-=q.top();
			sol+=s;
			q.pop();
			if(q.empty()) break;
			q.push(-s);
		}
		cout<<sol<<'\n';
		cin>>n;
	}
	return 0;
}
