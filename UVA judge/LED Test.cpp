//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=357
#include <bits/stdc++.h>

using namespace std;

bool bad[10],stop=false;
string C[10],A[20];
int n;

ofstream fout("test.out");

bool valid(int c,int n){
	bool b[10];
	memset(b,0,10);
	for(int i=0;i<7;i++){
			if((!bad[i] && C[n][i]!='Y' && A[c][i]=='Y')||( bad[i] && A[c][i]=='Y')){
				return false;
			}else if(C[n][i]=='Y' && A[c][i]=='N'){
				b[i]=1;
			}
	}
	for(int i=0;i<7;i++){
		if(b[i])bad[i]=b[i];
	}
	return true;
}

void bk(int k,int max){
	if(k==n){
		stop=true;
		return;
	}
	if(valid(k,max) && (max||k==n-1)){
		bk(k+1,max-1);
	}
}

int main(){
	C[0]="YYYYYYN";C[1]="NYYNNNN";
	C[2]="YYNYYNY";C[3]="YYYYNNY";
	C[4]="NYYNNYY";C[5]="YNYYNYY";
	C[6]="YNYYYYY";C[7]="YYYNNNN";
	C[8]="YYYYYYY";C[9]="YYYYNYY";
	cin>>n;
	while(n){
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		stop=false;
		for(int i=9;i>=0 && !stop;i--){
			memset(bad,0,10);
			bk(0,i);
		}
		if(stop) cout<<"MATCH\n";
		else cout<<"MISMATCH\n";
		cin>>n;
	}
	return 0;
}
