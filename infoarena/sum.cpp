//Condition of the problem: https://www.infoarena.ro/problema/sum

#include <bits/stdc++.h>
#define ll long long
#define NMAX 100010
using namespace std;
 
ll P[NMAX];
 
void phi(){
	for(int i=2;i<=NMAX;i++)P[i]=i-1;
	for(int i=2;i<=NMAX;i++){
		if(P[i]==i-1)
		for(int j=i;j<=NMAX;j+=i){
			int c=P[j]/i;
			P[j]-=c;
		}
	}
}
 
int main(){
	ifstream cin("sum.in");
	ofstream cout("sum.out");
	int n;
	cin>>n;
	phi();
	while(n--){
		int x;
		cin>>x;
		cout<<2*x*P[x]*1LL<<'\n';
	}
	return 0;
}
