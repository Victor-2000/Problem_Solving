//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=403
#include <bits/stdc++.h>

using namespace std;

bool isst[4],isJ[4],isQ[4],isK[4];
char Pos[4]={'S','H','D','C'};
int N[4];
char c[2];

void eval(){
	char s;
	int p=0,cp=0;
	for(int i=0;i<4;i++)isst[i]=isJ[i]=isQ[i]=isK[i]=N[i]=0;
	//Citirea cu regula 1
	for(int i=0;i<13;i++){
		if(i!=0) cin>>c;
		for(int j=0;j<4;j++){
			if(c[1]==Pos[j]){
			if(c[0]=='A'){
			 isst[j]=true;
			 p+=4;
			}else if(c[0]=='K'){
				isK[j]=true;
				p+=3;
			}else if(c[0]=='Q'){
				isQ[j]=true;
				p+=2;
			}else if(c[0]=='J'){
				isJ[j]=true;
				p+=1;
			}
			N[j]++;
			break;
			}
		}
	}
	//Regulile: 2,3,4 si aflam daca toate semnele sunt oprite
	for(int i=0;i<4;i++){
		if(isK[i] && N[i]<=1)p--; else if(isK[i])isst[i]=true; 
		if(isQ[i] && N[i]<=2)p--; else if(isQ[i])isst[i]=true;
		if(isJ[i] && N[i]<=3)p--;
	} 
	//Pastrarea valorii cu ignorarea regulilor : 5,6,7
	cp=p;
	
	//Regulile: 5,6,7
	for(int i=0;i<4;i++) if(N[i]==2)p++; else if(N[i]<=1)p+=2;
	
	if(cp>=16 && isst[0] && isst[1] && isst[2] && isst[3]){
		cout<<"BID NO-TRUMP\n";
	} else if(p>=14){
		//Aflam s(semnul cu cele mai multe carti)
		int mx=0;
		for(int i=0;i<4;i++){
			if(N[mx]<N[i])mx=i;
		}
		s=Pos[mx];
		cout<<"BID "<<s<<'\n';
	}else{
		cout<<"PASS\n";
	} 
}

int main(){
	//Problema nu era in implementare ci in citire!!! La citire nu folosi !EOF curat ci scanf("%s",c)!=EOF (sau ==1) (merge numai la tabele de char nu la string!!!) 
	while(scanf("%s",c)!=EOF){
		eval();
	}
	return 0;
}
