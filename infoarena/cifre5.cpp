//Condition of the problem: https://www.infoarena.ro/problema/cifre5

#include <bits/stdc++.h>
 
using namespace std;
 
int N[10]={6,2,5,5,4,5,6,3,7,6},v,DPu[10]={1,5,1,2,2,3,1,2,0,0},DPc[10]={2,7,2,3,3,4,2,5,1,2};
 
ifstream fin("cifre5.in");
ofstream fout("cifre5.out");
 
int main(){
	fin>>v;
	if(v==1){
		int s=0;
		char c;
		while(fin>>c)if(c>='0'&&c<='9')s+=N[c-'0'];
		fout<<s;
	}else{
		string nr;
		long long s=0,p=1;
		fin>>nr;
		int l=nr.size();
		for(int i=l-1;i>=0;i--){
			if(nr[i]>='0' && nr[i]<='9'){
				s+=DPu[nr[i]-'0']*p;
				p*=DPc[nr[i]-'0'];
			}
		}
		fout<<s;
	}
	return 0;
}
