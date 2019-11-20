//Condition of the problem: https://www.infoarena.ro/problema/perle
#include <bits/stdc++.h>
 
using namespace std;
 
struct sir{
	string s;
	int l;
};
 
int n,ic=0;
sir a;
string s;
 
void eC ();
 
void eB(){
	if(a.s[s.length()]=='2' && s.length()+1<=a.l){
		s+="2";
		eB();
		return;
	} else if(a.s[s.length()]=='1' && a.s[s.length()+2]=='3' && s.length()+3<=a.l){
		s+="1A3A";
		eC();
		return;
	}
	return;
}
 
void eC(){
	if(a.s[s.length()]=='2' && s.length()<=a.l){
		s+='2';
		return;
	} 
	else if(a.s[s.length()]=='1' && a.s[s.length()+1]=='2' && s.length()+2<=a.l){
		return;
	} 
	else if(a.s[s.length()]=='3' && s.length()+2<=a.l){
		 s+='3';
		 eB();
		 eC();
		 return;
	}
	return;
}
 
bool egal(string a, string b){
	if (a.size()!=b.size()) return 0;
	else
	for (int i=0;i<a.size();i++){
		if(a[i]!=b[i] && a[i]!='A') return 0;
	}
	return 1;
}
 
ifstream fin("perle.in");
ofstream fout("perle.out");
 
void calcs(){
	eC();
	ic=0;
	bool sol = egal(s,a.s);
	//cout<<s<<'\n';
	if(!sol){
		s.clear();
		eB();
		sol = egal(s,a.s);
	} 
	s.clear();
	fout<<sol<<'\n';
}
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		char c;
		a.s.clear();
		fin>>a.l;
		for(int j=0;j<a.l;j++){
			fin>>c;
			a.s+=c;
		}
		if(a.l == 1){
			fout<<1<<'\n';
		}else if(a.l>=3){
			calcs();	
		} else fout<<0<<'\n';
		ic=0;
	}]
	return 0;
}
