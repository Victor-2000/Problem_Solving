//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=430
#include <bits/stdc++.h>

using namespace std;

//ofstream fout("test.out");

int main(){
	int r;
	string g,a;
	bool A[1000000];
	scanf("%d",&r);
	while(r!=-1){
		cin>>a;
		cin>>g;
		int la=a.size(),lg=g.size();
		printf("Round %d\n",r);
		//fout<<"Round "<<r<<"\n";
		int l=7;
		for(int i=0;i<la;i++)
			A[i]=false;
		for(int i=0;i<lg;i++){
			bool guessed = false;
			for(int j=0;j<la;j++){
				if(g[i]==a[j]){
				if(!guessed) guessed=true;
				A[j]=true;
				}
			}
			if(!guessed)l--;
			if(!l) break;
		}
		bool s=true;
		for(int i=0;i<la;i++){
			if(!A[i])s=false;	
		}
		if(s) printf("You win.\n");
		else if(l) printf("You chickened out.\n");
		else printf("You lose.\n");
		scanf("%d",&r);	
	}
	return 0;
}
