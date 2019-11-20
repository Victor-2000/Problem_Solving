//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=82
#include <bits/stdc++.h>

using namespace std;

string A;

int main(){
	cin>>A;
	while(A!="#"){
		int l=A.size();
		if(next_permutation(A.begin(),A.end()))
			for(int i=0;i<l;i++)
				cout<<A[i];
		else cout<<"No Successor";
		cout<<'\n';
		cin>>A;
	}
	return 0;
}
