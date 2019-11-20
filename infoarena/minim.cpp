//Condition of the problem: https://www.infoarena.ro/problema/minim

#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector <int> nr,ind;
 
ifstream fin("minim.in");
ofstream fout("minim.out");
 
int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		int c;
		fin>>c;
		nr.push_back(-c);
		ind.push_back(i+1);
	}
	int l,s,sol,p,ps,u;
	while(l=nr.size()){
		s=u=p=ps=0;
		sol=-10000001;
		for(int i=0;i<l;i++){
			s+=nr[i]; 
			if(sol<s || (sol==s && i-ps<u-p)){
				sol=s;
				p=ps;
				u=i;
			}
			if(s<0){
				ps=i+1;
				s=0;
			}
		}
		fout<<-sol<<' '<<ind[p]<<' '<<ind[u]<<'\n';
		nr.erase(nr.begin()+p,nr.begin()+u+1);
		ind.erase(ind.begin()+p,ind.begin()+u+1);
	}
	return 0;
}

