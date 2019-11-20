//Condition of the problem: https://www.infoarena.ro/problema/dreptunghi

#include <bits/stdc++.h>
 
using namespace std;
 
int euclid(int a,int b){
	if(b) return (a/b)*b+euclid(b,a%b);
	return 0;
}
 
int main(){
	ifstream cin("dreptunghi.in");
	ofstream cout("dreptunghi.out");
	int a,b;
	cin>>a>>b;
	cout<<euclid(a,b);
	return 0;
}
