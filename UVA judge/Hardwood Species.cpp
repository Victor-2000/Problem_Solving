//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167

# include <bits/stdc++.h>

using namespace std;

int main(){
	int c;
	cin>>c;
	while(c--){
		string s;
		map <string,int> sc;
		vector <string> V;
		sc.clear();
		V.clear();
		while(s[0]=='\0')getline(cin,s);
		int nos=0;
		while(s[0]!='\0'){
			sc[s]++;
			if(sc[s]==1){
				V.push_back(s);
			}
			nos++;
			getline(cin,s);
		}
		sort(V.begin(),V.end());
		for(int i=0;i!=V.size();i++){
			cout<<V[i]<<' ';
			printf("%0.4f\n",(float)sc[V[i]]*100/nos);
		}
		if(c)cout<<'\n';
	}
	return 0;
}
