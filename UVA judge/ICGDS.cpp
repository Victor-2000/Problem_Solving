//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146

#include <bits/stdc++.h>

using namespace std;

queue <int> q;
priority_queue <int> pq;
stack <int> s;

void clear(){
	while(!q.empty()) q.pop();
	while(!pq.empty()) pq.pop();
	while(!s.empty()) s.pop();
}

int main(){
	bool iss=1,isq=1,ispq=1;
	int n;
	while(cin>>n){
	for(int i=0;i<n;i++){
		int c,x;
		cin>>c>>x;
		if(c==1){
			if(iss)s.push(x);
			if(isq)q.push(x);
			if(ispq)pq.push(x);
		}else{
			if(iss && (s.empty() || s.top()!=x))iss=0;
			else if(!s.empty()) s.pop();
			if(isq && (q.empty() || q.front()!=x))isq=0;
			else if (!q.empty()) q.pop();
			if(ispq && (pq.empty() || pq.top()!=x))ispq=0;
			else if(!pq.empty()) pq.pop();
		}
	}
	clear();
	int res=iss+isq+ispq;
	if(!res) cout<<"impossible\n";
	else if(res>1) cout<<"not sure\n";
	else if(iss) cout<<"stack\n";
	else if(isq) cout<<"queue\n";
	else if(ispq) cout<<"priority queue\n";
	iss=1;isq=1;ispq=1;
	}
	return 0;
}
