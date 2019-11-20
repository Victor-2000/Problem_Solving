//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565

# include <bits/stdc++.h>

using namespace std;

set <int> S;

int main(){
	int ja,ji;
	cin>>ja>>ji;
	while(ja && ji){
		int c;
		for(int i=0;i<ja;i++){
			cin>>c;
			S.insert(c);
		}
		int ncd=0;
		for(int i=0;i<ji;i++){
			cin>>c;
			if(S.find(c)!=S.end())ncd++;
		}
		S.clear();		
		cout<<ncd<<'\n';
		cin>>ja>>ji;
	}
	return 0;
}
