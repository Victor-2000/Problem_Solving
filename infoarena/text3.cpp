//Condition of the problem: https://www.infoarena.ro/problema/text3

#include <bits/stdc++.h>
#define MAX 20010
 
using namespace std;
 
int D[MAX],ne=1,P[MAX],m=0,mi,T[MAX];
string C[MAX];
 
int main(){
	ifstream cin("text3.in");
	ofstream cout("text3.out");
	string s;
	while(cin>>C[ne]){
		ne++;
	}
	for(int i=ne-1;i>=1;i--){
		int l=C[i][C[i].size()-1],f=C[i][0];
		if(D[f]<D[l]+1){
			D[f]=D[l]+1;
			P[i]=T[l];
			T[f]=i;
			if(D[f]>m){
				m=D[f];
				mi=i;
			}
		}
	}
	cout<<ne-1<<'\n';
	cout<<ne-m-1<<'\n';
	while(mi!=0){
		cout<<C[mi]<<'\n';
		mi=P[mi];
	}
	return 0;
}
