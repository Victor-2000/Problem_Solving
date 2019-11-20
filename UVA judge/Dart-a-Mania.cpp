//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676

#include <bits/stdc++.h>

using namespace std;

int main(){
	int val[100],l=0;
	bool v[100];
	memset(v,0,65);
	for(int i=1;i<=20;i++){
		v[i]=1;
		v[2*i]=1;
		v[3*i]=1;
	}
	v[50]=1;
	v[0]=1;
	for(int i=0;i<65;i++)if(v[i])val[l++]=i;
	int s;
	cin>>s;
	while(s>0){
		int p=0,c=0;
		for(int i1=0;i1<l;i1++){
			for(int i2=0;i2<l;i2++){
				for(int i3=0;i3<l;i3++)
					if(val[i1]+val[i2]+val[i3]==s)p++;
			}
		}
		for(int i1=0;i1<l;i1++){
			for(int i2=i1;i2<l;i2++){
				for(int i3=i2;i3<l;i3++)
				 if(val[i1]+val[i2]+val[i3]==s)c++;
			}
		}
		if(c){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",s,c,s,p);
		}else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",s);
		cin>>s;
		if(s>=0){
			for(int i=0;i<70;i++){
				printf("*");
			}
			printf("\n");
		}
	}
	printf("END OF OUTPUT\n");
}
