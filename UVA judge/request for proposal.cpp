//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1082

#include <bits/stdc++.h>

using namespace std;

string s,a;
int n=0,p;

//ofstream fout("RFP.out");

int main(){
	int rq=0;
	while(1){
		int rc=0;
		float dc=0;
		string sc;
		scanf("%d  %d",&n,&p);
		if(!n) break;
		for(int i=0;i<n;i++){
			scanf("\n");
			getline(cin,a);
		}
		for(int i=0;i<p;i++){
			getline(cin,s);
			int r;
			float d;
			scanf("%f %d",&d,&r);
			for (int i = 0;i<r;i++){
				scanf("\n");
				getline(cin,a);
			} 
			if(rc<r||(rc==r && dc>d)){
				rc=r;
				dc=d;
				sc=s;
			} 
		}
		rq++;
		if(rq>1)
		cout<<'\n';
		cout<<"RFP #"<<rq<<"\n";
		cout<<sc<<'\n';
	}
	return 0;
}
