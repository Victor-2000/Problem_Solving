//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2612

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int A,B,C,x,y,z;
		bool sol=false;
		cin>>A>>B>>C;
		for(x=-22;x<=22 && !sol;x++){
			for(y=-100;y<=100 && !sol;y++){
				z=A-y-x;
				if(x!=z && y!=z && x!=y && x+y+z==A && x*y*z==B && x*x+y*y+z*z==C) sol=true;
			}
		}
		if(sol)printf("%d %d %d\n",--x,--y,z);
		else printf("No solution.\n");
	}
	return 0;
}
