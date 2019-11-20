//Condition of the problem: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2183

#include <bits/stdc++.h>
#define MAX 15

using namespace std;

int main(){
	int n,m,f[MAX];
	float d[110];
	cin>>n;
	while(n){
		cin>>m;
		for(int i=0;i<n;i++){
			cin>>f[i];
		}
		int cr,l=0;
		for(int i=0;i<m;i++){
			cin>>cr;
			for(int i=0;i<n;i++){
				d[l++]=(float)f[i]/cr;
			}
		}
		sort(d,d+l);
		float s,smax=0;
		for(int i=1;i<l;i++){
			s=d[i]/d[i-1];
			if(s>smax)smax=s;
		}
		printf("%.2f\n",smax);
		cin>>n;
	}
	return 0;
}
