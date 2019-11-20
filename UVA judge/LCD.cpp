//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1113

#include <bits/stdc++.h>

using namespace std;

const int MAX=110;

int NQ[MAX];

void clear(){
	for(int i=0;i<MAX;i++){
		NQ[i]=0;
	}
}

bool isEmpty(){
	int sol=0;
	for(int i=0;i<MAX;i++){
		sol|=NQ[i];
	}
	return !sol;
}

int main() {
	int SET;
	scanf("%d",&SET);
	while(SET--){
		int n=0,s=0,q=0;
		queue <int> Q[MAX];
		stack <int> S;
		scanf("%d %d %d",&n,&s,&q);
		clear();
		for(int i=1;i<=n;i++){
			int nc;
			scanf("%d",&nc);
			for(int j=1;j<=nc;j++){
			 int c;
			 scanf("%d",&c);
			 NQ[i]++;
			 Q[i].push(c);	
			}
		}
		int pos=1,cs=0,time=0;
		//cout<<isEmpty();
		while(!isEmpty() || cs!=0){
			if(pos==4){
			 pos=4;	
			}
			while(cs>0 && NQ[pos]==q && S.top()==pos){
				cs--;
				time++;
				S.pop();
			}
			while(cs>0 && NQ[pos]<q){
				cs--;
				time++;
				if(S.top()!=pos){
					NQ[pos]++;
					Q[pos].push(S.top());
				}
				S.pop();
			}
			while(cs>0 && NQ[pos]==q && S.top()==pos){
				cs--;
				time++;
				S.pop();
			}
			while(NQ[pos]>0 && cs<s){
				cs++;
				time++;
				NQ[pos]--;
				S.push(Q[pos].front());
				Q[pos].pop();
			}
			time+=2;
			pos=(pos+1)%(n+1);
			if(!pos)pos=1;
		}
		time-=2;
		cout<<time<<'\n';
	}
	return 0;
}
