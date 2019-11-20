//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1975

# include <bits/stdc++.h>

using namespace std;

int main(){
	int c;
	cin>>c;
	while(c--){
		int l,m;
		cin>>l>>m;
		l*=100;//m to cm
		string b;
		queue <int> cars[2];
		int cl;
		for(int i=0;i<m;i++){
			cin>>cl>>b;
			if(b[0]=='l')cars[0].push(cl);
			else cars[1].push(cl);
		}
		int nr=0;//0-left 1-right
		while(!(cars[0].empty() && cars[1].empty())){
			int lc=0;
			while(!cars[nr%2].empty() && lc+cars[nr%2].front()<=l){
				lc+=cars[nr%2].front();
				cars[nr%2].pop();
			}
			nr++;
		}
		cout<<nr<<'\n';
	}
	return 0;
}
