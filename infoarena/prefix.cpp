//Condition of the problem: https://www.infoarena.ro/problema/prefix

#include <bits/stdc++.h>
 
using namespace std;
int P[1000010];
int main(){
	ifstream cin("prefix.in");
	ofstream cout("prefix.out");
	int t;
	cin>>t;
	while(t--){
		string A;
		int p=0,m=0,ind=-1;
		cin>>A;
		for(int i=1;i<A.size();i++){
			while(A[i]!=A[p] && p){
				p=P[p-1];
			}
			if(A[i]==A[p]){
				p++;
			}
			P[i]=p;
		}
		int s=0;
		for(int i=A.size()-1;i>0;i--)
			if(P[i]>=(i+1)/2 && !(P[i]%(i-P[i]+1))){
				s=i;
			 	break;		
			}
		if(s)cout<<s+1<<'\n';
		else cout<<"0\n";
	}
	return 0;
}
