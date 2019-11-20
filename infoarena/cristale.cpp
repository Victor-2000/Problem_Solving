//Condition of the problem: https://www.infoarena.ro/problema/cristale
 
#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("cristale.in");
ofstream fout("cristale.out");
 
char a,b,c;
string k;
int sum;
 
void trans(int j){
	bool ch = true;
	while(ch && k.size()!=1){
		ch = false;
		while(j+1>=k.size() || (k[j-1]!=k[j] && j)) j--; 
		while(j+2<k.size() && k[j]==k[j+1]) j++; 
		if(k[j+1]!=k[j]){
			k[j] = (char)(sum-k[j]-k[j+1]);
			ch = true;
			k.erase(j+1,1);
		}
	}
}
 
int main(){
	fin>>a>>b>>c;
	sum=a+b+c;
	int p,s;
	fin>>p;
	for (int i=0;i<p;i++){
		int n;
		fin>>n;
		fin>>k;
		s=k.size();
		if (n>1)
			trans(0);
	if(k.size()<=2 || s==k.size())
		fout<<k.size()<<'\n';
	else fout<<2-k.size()%2<<'\n';
	}
	return 0;
}
