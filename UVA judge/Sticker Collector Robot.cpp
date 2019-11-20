//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2931

#include <bits/stdc++.h>

using namespace std;

char T[110][110];
int n,m,s,o,xc,yc,xd[4]={0,1,0,-1},yd[4]={-1,0,1,0};

int main(){
	cin>>n>>m>>s;
	while(n){
		o=-1;
		int sol=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>T[i][j];
				if(T[i][j]!='#' && T[i][j]!='.' && T[i][j]!='*'){
					if(T[i][j]=='N')o=0;
						else if(T[i][j]=='L')o=1;
							else if(T[i][j]=='S')o=2;
								else if(T[i][j]=='O')o=3;
					xc=j;
					yc=i;
				}
			}
		}
		for(int i=0;i<s;i++){
			char c;
			cin>>c;
			if(c=='D') o+=1;
			else if(c=='E') o-=1;
			else if(c=='F'){
				if(yc+yd[o]>=0 && yc+yd[o]<n && xc+xd[o]>=0 && xc+xd[o]<m && T[yc+yd[o]][xc+xd[o]]!='#'){
					if(T[yc+yd[o]][xc+xd[o]]=='*'){
						sol++;
						T[yc+yd[o]][xc+xd[o]]='.';
					}
					yc+=yd[o];
					xc+=xd[o];
				}
			}
			if(o==-1)o=3;
			o%=4; 
		}
		cout<<sol<<'\n';
		cin>>n>>m>>s;
	}
	return 0;
}
