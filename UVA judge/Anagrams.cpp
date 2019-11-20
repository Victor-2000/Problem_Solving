//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=92
#include <bits/stdc++.h>

using namespace std;

ofstream fout("test.out");

vector <string> W;
int nr;

bool isPair(string a,string b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	while(a[0]==' ') a.erase(0,1);
	while(b[0]==' ') b.erase(0,1);
//	cout<<a<<'\n';
//	cout<<b<<'\n';
	if(a.size()==b.size()){
		int l=a.size();
		for(int i=0;i<l;i++){
			if(a[i]!=b[i]) return false;
		}
	}else return false;
return true;
}

bool comp(string a,string b){
	return a>b;
}

int main (){
	cin>>nr;
	string s;
	cin.ignore();
	while(nr--){
		int m=0,n=0;
		getline(cin,s);
		do{	
			W.push_back(s);
			getline(cin,s);
		}while(s!="");
		sort(W.begin(),W.end(),comp);
		int l=W.size();
		for (int i=l-1;i>=0;i--){
			for (int j=i-1;j>=0;j--){
				if(isPair(W[i],W[j])){
					if(W[i]<W[j]) cout<<W[i]<<" = "<<W[j]<<'\n';
					else cout<<W[j]<<" = "<<W[i]<<'\n';
				}
			}
			W.pop_back();
		}
		if(nr)cout<<'\n';
	}
	return 0;
}
