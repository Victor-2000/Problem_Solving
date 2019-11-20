//Condition of the problem: https://www.infoarena.ro/problema/avarcolaci

#include <bits/stdc++.h>
 
using namespace std;
 
int M[1000000];
int t,n;
 
int main(){
	ifstream cin("avarcolaci.in");
	ofstream cout("avarcolaci.out");
	//cout<<sizeof (M)/(1024*1024);
	cin>>t;
	while(t--){
		cin>>n;
		int c,l=n*2,s=0;
		for(int i=1;i<=l;i++){
			cin>>M[i];
		}
		sort(M+1,M+l+1);
		c=M[n+1];
		int i=n+1;
		while(M[i]==M[n+1]){
			i--;
		}
		s+=n-i;
		if(M[(n+n+1)-s]==M[n+1])cout<<M[n+1]<<'\n';
		else cout<<"Mozart\n";
	}
	return 0;
}
