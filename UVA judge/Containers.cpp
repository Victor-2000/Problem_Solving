//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3503

#include <bits/stdc++.h>

using namespace std;

stack <char> V[100000];

int main(){
	string s;
	int nr=0;
	getline(cin,s);
	while(s[0]!='e'){
		nr++;
		for(int i=0;i<50;i++){
			while(!V[i].empty())V[i].pop();
		}
		int l=s.size();
		int sol=0;
		for(int i=0;i<l;i++){
			bool stop=0;
		 	for(int j=0;j<sol && !stop;j++){
			 if(s[i]<=V[j].top()){
			 		V[j].push(s[i]);
			 		stop=1;
			 	} 
			 }
			 if(!stop){
			 	V[sol].push(s[i]);
			 	sol++;
			 } 
		}
		printf("Case %d: %d\n",nr,sol);
		getline(cin,s);
	}
	return 0;
}
