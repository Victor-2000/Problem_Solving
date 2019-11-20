//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=514

#include <bits/stdc++.h>

using namespace std;

int h,u,d,f,dc=0;
float cd=0,ft;

int main (){
	scanf("%d %d %d %d",&h,&u,&d,&f);
	ft=1-(1.0*f/100);
	//cout<<ft<<'\n';
	while(h){
		while(cd>=0 && cd<h){
			if(dc){
				cd=cd+1.0*u*ft;
				if(ft>=1.0*f/100)
				ft-=1.0*f/100;
			}
			else cd=u;
			if(cd>h){
				dc++;
			//	cout<<dc<<' '<<cd<<' '<<ft<<'\n';
				break;
			} 
			cd-=d;
			dc++;
			//cout<<dc<<' '<<cd<<' '<<ft<<'\n';
		}
		if(cd>h) printf("success ");
		else printf("failure ");
		printf("on day %d\n",dc);
		scanf("%d %d %d %d",&h,&u,&d,&f);
		dc=0;cd=0;
		ft=1-(1.0*f/100);
	}
	return 0;
}
