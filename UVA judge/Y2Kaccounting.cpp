//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1517

#include <bits/stdc++.h>

using namespace std;

int s,d,sol=-1;
bool rep[13];

void bk(int m){
	if(m>4){
		int sum=0;
		for(int i=m-5;i<m;i++)sum+=rep[i]?-d:s;
		if(sum>=0)return;
	}
	if(m==12){
		int sum=0;
		for(int i=0;i<12;i++)sum+=rep[i]?-d:s;
		if(sum>1000000)
		 sum=sum;
		sol=max(sol,sum);
	}else{
		rep[m]=0;
		bk(m+1);
		rep[m]=1;
		bk(m+1);
	}
}

int main(){
	while(cin>>s>>d){
		memset(rep,0,13);
		sol=-1;
		bk(0);
		if(sol!=-1)
		cout<<sol<<'\n';
		else cout<<"Deficit\n";
	}
	return 0;
}
