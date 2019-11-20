//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1318

#include<bits/stdc++.h>

using namespace std;

int T,mx[4]={0,1,0,-1},my[4]={-1,0,1,0};
string s[65];
char C[4];

ofstream fout("test.out");

int main(){
	cin>>T;
	C[0]='N';C[1]='E';
	C[2]='S';C[3]='W';
	for(int k=0;k<T;k++){
		int n,m,nc,mc,oc=0;
		string si;
		char c=0;
		cin>>n>>m;
		getline(cin,si);
		for(int i=1;i<=n;i++){
			getline(cin,s[i]);
		}
		cin>>nc>>mc;
		while(c!='Q'){
			scanf("%c",&c);
			switch(c){
				case 'R':{
					oc++;
					oc%=4;	
					break;
				}
				case 'L':{
					oc--;
					if(oc==-1) oc=3;
					break;
				}
				case 'F':{
					if(s[nc+my[oc]][mc+mx[oc]-1]!='*'){
						nc+=my[oc];
						mc+=mx[oc];
					}
					break;
				}
			}
		}
		if(k)cout<<'\n';
		cout<<nc<<' '<<mc<<' '<<C[oc]<<'\n';
	}
	return 0;
}
