//Condition of the problem: https://www.infoarena.ro/problema/fractii
#include <bits/stdc++.h>
#define NMAX 1000010
#define ll long long
using namespace std;
 
ll P[NMAX];
ll s=0;
 
void phi(int n){
	for(int i=0;i<=n;i++)P[i]=i-1;
	for(int i=2;i<=n;i++){
		s+=P[i];
		if(P[i]==i-1)//Daca i e prim cercetam toti multiplii lui i si le scadem (astfel scadem toti multiplii numerelor prime din P[j])
		for(int j=i;j>0 && j<=n;j+=i){
			int c=P[j]/i;
			P[j]-=c;
		}
	}
}
 
int main(){
	int n;
	ifstream cin("fractii.in");
	ofstream cout("fractii.out");
	cin>>n;
	phi(n);
	cout<<s*2+1;
	return 0;
}
