//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3084

#include <bits/stdc++.h>

using namespace std;

int msb(int a){
	int m=0;
	while(a){
		a/=2;
		m++;
	}
	return m;
}

int main(){
	int n;
	cin>>n;
	while(n){
		int l=msb(n);
		int a=0,b=0;
		bool ip=0;
		for(int i=0;i<l;i++){
			if(n&(1<<i)){
				if(ip){
					ip=0;
					b|=1<<i;
				}else{
					ip=1;
					a|=1<<i;
				}
			}
		}
		printf("%d %d\n",a,b);
		cin>>n;
	}
}
