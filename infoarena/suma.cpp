//Condition of the problem: https://www.infoarena.ro/problema/suma
#include <bits/stdc++.h>
 
using namespace std;
 
long long R[30010];
 
int main(){
	ifstream cin("suma.in");
	ofstream cout("suma.out");
	int n,p;
	cin>>n>>p;
	for(int i=2;i<=p+1;i++){
		R[i]=R[i-1]+(i*(i-1))%p;
		R[i]%=p;
	}
	cout<<((n/p)*R[p+1])%p+R[n%p];
	return 0;
}
