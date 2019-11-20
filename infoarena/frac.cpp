//Condition of the problem: https://www.infoarena.ro/problema/frac

#include <bits/stdc++.h>
#define ll long long
#define MAXN 120000 
using namespace std;
 
bool E[MAXN];
vector <ll> P,D;
 
ll f(ll a){
	int l=D.size(),c;
	ll s=a;
	for(int bm=1;bm<(1<<l);bm++){
		ll fact=1;
		c=0;
		for(int i=0;i<l;i++){
			if(bm&(1<<i)){
				fact*=D[i];
				c++;
			}
		}
		if(c%2)s-=a/fact;
		else s+=a/fact;
	}
	return s;
}
 
ll cbin(ll nr){
	ll hi=(1ll<<61),lo=0,mi=(hi+lo)/2;
	while(hi>lo){
		ll c=f(mi);
		if(nr<=c)hi=mi;
		else lo=mi+1;
		mi=(hi+lo)/2;
	}
	return lo;
}
 
int main(){
	ifstream cin("frac.in");
	ofstream cout("frac.out");
	ll n,p,b;
	cin>>n>>p;
	for(int i=2;i<MAXN;i++){
		if(!E[i]){
			P.push_back(i);
			if(i*i<MAXN)
			for(int j=i*i;j<MAXN && j>0;j+=i){
				E[j]=1;
			}
		}	
	}
	int i=0;
	b=n;
	while(n>1){
		if(b%P[i]==0){
			D.push_back(P[i]);
			while(n%P[i]==0)n/=P[i];
		}
		if(i>sqrt(n) && n>1){
			D.push_back(n);
			n=1;
		}
		i++;
	}
	cout<<cbin(p);
	return 0;
}
