//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
#include <bits/stdc++.h>

using namespace std;

int val[1001];
stack <int> S;

int main(){
	int n;
	cin>>n;

	while(n){
		int c=0;
		cin>>c;	
		while(S.size())S.pop();
		while(c){
			val[0]=c;
			for (int j=1;j<n;j++){
				cin>>c;
				val[j]=c;
			}
			c=0;
			int i=0;
			while(c<=n && i<n){
				while(c!=val[i] && c<=n){
					c++;
					S.push(c);
				} 
				if(c>n && S.size()) S.pop();
				while(S.size() && S.top()==val[i]){
					S.pop();
					i++;
				}
			}
			if(i==n)printf("Yes\n");
			else printf("No\n");
			while(S.size())S.pop();
			cin>>c;
		}
		cout<<'\n';
		cin>>n;
	}
	return 0;
}
