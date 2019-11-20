//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	multiset <int> urn;
	urn.clear();
	cin>>n;
	while(n){
	long long sc=0;
	 for(int i=0;i<n;i++){
		int b;
	   cin>>b;
	   for(int j=0;j<b;j++){
	   		int c;
	   		cin>>c;
	   		//introducem in urn
			urn.insert(c);	
	   }
	  multiset <int> :: iterator o=urn.end();
	  o--;
	  sc+=(int)*o-(int)*urn.begin();
	  urn.erase(urn.begin());
	  urn.erase(o);
	}
	urn.clear();
	cout<<sc<<'\n';
	cin>>n;
	} 
	return 0;
}
