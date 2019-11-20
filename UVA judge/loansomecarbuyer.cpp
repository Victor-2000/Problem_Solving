//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1055

# include <bits/stdc++.h>

using namespace std;

struct dep {
	int m;
	double r;
};

double val,loan,carp,dp;
int m,n,mc;
dep A[110];

int solve(){
	mc=1;
	//scanf("%f %f %d",&dp,&loan,&n);
	cin>>dp>>loan>>n;
	for(int i=0;i<n;i++) cin>>A[i].m>>A[i].r;//scanf("%d %f",&A[i].m,&A[i].r);
	carp=(loan+dp)*(1-A[0].r);
	val = loan/m;
	int i=1;
	while(mc<m && i<n){
		if (loan<carp) return mc;
		if(mc == A[i].m) i++;
		carp*=(1-A[i-1].r);
		loan-=val;
		mc++;
	}
	for(int i = mc;i<=m;i++){
		if (loan<carp) return i;
		carp*=(1-A[n-1].r);
		loan-=val;
	}
}

int main(){
	int s=0;
	cin>>m;
	//scanf("%d ",&m);
	while(m>0){
		s=solve()-1;
		if(s==1) printf("1 month\n");
		else printf("%d months\n",s);
		cin>>m;
		//scanf("%d ",&m);
	}
	return 0;
}
