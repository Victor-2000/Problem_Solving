//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3703

#include <bits/stdc++.h>

using namespace std;

ofstream fout("test.out");

char G1[5][6],G2[5][6],cps[5],last[7800][5];
bool stop=false;
int nr,cnr;

bool eq(){
	for(int i=0;i<cnr;i++){
		bool e=true;
		for(int j=0;j<5;j++){
			if(cps[j]!=last[i][j]){
				e=false;
				break;
			}
		}
		if(e)return true;
	}
	return false;
}

void bk(int k){
	if(k>=5){
		if(!eq()){
			cnr++;
			for(int i=0;i<5;i++) last[cnr-1][i]=cps[i];
			if(cnr==nr){
				stop=true;
			}
		}
		return;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6 && G1[k][i]>=G2[k][j];j++){
			if(G1[k][i]==G2[k][j]){
				cps[k]=G1[k][i];
				bk(k+1);
				if(stop)return;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>nr;
		for(int i=0;i<6;i++){
			string s;
			cin>>s;
			for(int j=0;j<5;j++){
				G1[j][i]=s[j];
			}
		}
		for(int i=0;i<6;i++){
			string s;
			cin>>s;
			for(int j=0;j<5;j++){
				G2[j][i]=s[j];
			}
		}
		for(int i=0;i<5;i++){
			sort(G1[i],G1[i]+6);
			sort(G2[i],G2[i]+6);
		}
		stop=false;
		cnr=0;
		memset(cps,0,6);
		memset(last,0,6);
		bk(0);
		if(stop)for(int i=0;i<5;i++)cout<<cps[i];
		else cout<<"NO";
		cout<<'\n';
	}
	return 0;
}
