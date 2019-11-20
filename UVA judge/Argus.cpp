//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3644

#include <bits/stdc++.h>

using namespace std;

struct qu{
	long long Q,t;
};

bool cmp(qu a,qu b){
	
	if(a.t<b.t) return 1;
	else if(a.t>b.t) return 0;
	else return a.Q<b.Q;
	
}

int main(){
	vector <qu> pq;
	qu rq[10010];
	char s[10];
	int q,t,l=0;
	scanf("%s",s);
	while(s[0]!='#'){
		scanf("%d %d",&q,&t);
		rq[l].Q=q;
		rq[l].t=t;
		l++;
		scanf("%s",s);
	}
	int k;
	cin>>k;
	for(int i=0;i<l;i++){
	 for(int j=0;j<k;j++){
	 	qu c;
	 	c.Q=rq[i].Q;
	 	c.t=rq[i].t*(j+1);
	 	pq.push_back(c);
	 	}
	}
	sort(pq.begin(),pq.end(),cmp);
	for(int i=0;i<k;i++){
		cout<<pq[i].Q<<'\n';
	} 
	return 0;
}
