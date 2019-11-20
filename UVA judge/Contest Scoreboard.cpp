//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1199

#include <bits/stdc++.h>

using namespace std;

struct contestant{
	int cn,PN[20];
	bool PS[20];
	long long pt,ps;
};

contestant A[110];

bool comp(contestant a,contestant b){
	if(a.ps==b.ps){
		if(a.pt==b.pt)
			return a.cn<b.cn;
		else return a.pt<b.pt;	
	}else return a.ps>b.ps;
}

int main(){
	int n;
	scanf("%d\n",&n);
	char nc;
	while (n--){
		int nr,p,t;
		char c;
		for(int i=0;i<=100;i++){
			A[i].ps=A[i].pt=A[i].cn=0;
			memset(A[i].PN,0,11);
			memset(A[i].PS,0,11);
		}
		char ar[10000];
		while(gets(ar) && ar[0]!='\0'){
			sscanf(ar,"%d %d %d %c",&nr,&p,&t,&c);
				A[nr].cn=nr;	
					if(!A[nr].PS[p]){
						if(c=='I')A[nr].PN[p]++;
						else if(c=='C'){
						 A[nr].pt+=t+A[nr].PN[p]*20;
						 A[nr].PS[p]=1;
						 A[nr].ps++;
					}
				}	
		}
		sort(A,A+101,comp);
		for(int i=0;i<101;i++){
			if(A[i].cn!=0)cout<<A[i].cn<<' '<<A[i].ps<<' '<<A[i].pt<<'\n';
		}
		if(n)cout<<"\n";
	}
	return 0;
}
