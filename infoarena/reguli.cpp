//Condition of the problem: https://www.infoarena.ro/problema/reguli

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll X[500010],P[500010],n;
 
int main(){
	ifstream cin("reguli.in");
	ofstream cout("reguli.out");
	cin>>n;
	ll p=0,l=n-1;
	for(int i=0;i<n;i++){
		cin>>X[i];
		if(i){
			X[i-1]=X[i]-X[i-1];
			if(i>1){
				while(p && X[i-1]!=X[p])p=P[p-1];
				if(X[i-1]==X[p])p++;
				P[i]=p;
			}
		}	
	}
	l-=P[l];
	cout<<l<<'\n';
	for(int i=0;i<l;i++)cout<<X[i]<<'\n';
	return 0;
}
