//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1861

#include <bits/stdc++.h>

using namespace std;

int main (){
	int sz,p,x[5]={1,0,-1,0},y[5]={0,-1,0,1};
	cin>>sz>>p;
	while(sz!=0){
		int i=sz/2+1,j=sz/2+1,num=0;
		int nr=1;
			for(int k=0;nr<p;k++){
				if(nr+k/2+1<p){
					nr+=(k/2+1);
					i+=(x[k%4]*(k/2+1));
					j+=(y[k%4]*(k/2+1));
				}else for(int l=0;l<=k/2 && nr<p;l++){
					nr++;
					i+=x[k%4];
					j+=y[k%4];
				}
			}
		printf("Line = %d, column = %d.\n",i,j);
		cin>>sz>>p;
	}
	return 0;
}
