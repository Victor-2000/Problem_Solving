//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1587

#include <bits/stdc++.h>

using namespace std;

int main (){
	int n,y;
	map <char,int> tr;
	tr['1']=1;
	tr['2']=2;
	tr['3']=3;
	tr['4']=4;
	tr['5']=5;
	tr['6']=6;
	tr['7']=7;
	tr['8']=8;
	tr['9']=9;
	tr['T']=tr['J']=tr['Q']=tr['K']=tr['A']=10;
	char c[2][53];
	bool isIn[53];
	scanf("%d",&n);
	for(int ca=1;ca<=n;ca++){
		int crd = 25,pss=0;
		y=0;
		for(int i=0;i<53;i++) isIn[i]=0;
		for(int i=52;i>0;i--){
			scanf("%c%c ",&c[0][i],&c[1][i]);
		}
		for(int i=0;i<3;i++){
			int x = tr[c[0][crd]];
			y+=x;
			pss=10-x;
			isIn[crd]=1;
			for(int j=0;j<=pss;j++) isIn[++crd]=1;
		}
		int i=0;
		while(i<y){
			if(isIn[52-i])y++;
			i++;
		}
		printf("Case %d: %c%c\n",ca,c[0][52-y+1],c[1][52-y+1]);
	}
	return 0;
}
