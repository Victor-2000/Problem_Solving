//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139

#include <bits/stdc++.h>

using namespace std;

deque <string> D;

string s,c;

int main(){
	getline(cin,s);
	while(s[0]!='\0'){
		int l=s.size();
		bool front=0,start=1;
		for(int i=0;i<l;i++){
			if(s[i]=='['){
					if(front){
						D.push_front(c);
						c.clear();	
					} else{
						D.push_back(c);
						c.clear();
					}
				front=1;
			}else if(s[i]==']'){
					if(front){
						D.push_front(c);
						c.clear();	
					} else{
						D.push_back(c);
						c.clear();
					}
				front = 0;
			}else c+=s[i];
		}
		if(front){
				D.push_front(c);
				c.clear();	
			} else{
				D.push_back(c);
				c.clear();
		}
		int ld=D.size(); 
		for(int i=0;i<ld;i++){
			int l=D[i].size();
			for(int j=0;j<l;j++){
				cout<<D[i][j];
			}
		}
		cout<<'\n';
		getline(cin,s);
		D.clear();
	}
	return 0;
}
