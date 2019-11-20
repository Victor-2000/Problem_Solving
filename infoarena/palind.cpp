//Condition of the problem: https://www.infoarena.ro/problema/palind

#include <bits/stdc++.h>
 
using namespace std;
 
int n,sol,A[30];
string s;
 
ifstream fin("palind.in");
ofstream fout("palind.out");
 
void clear(){
	for(int i=0;i<30;i++){
		A[i]=0;
	}
}
 
int main(){
	fin>>n;
	while(n--){
		fin>>s;
		clear();
		for(int i=0;i<s.size();i++){
			A[s[i]-'a']++;
		}
		bool go=1,sc=0;
		for(int i=0;i<30;i++){
			if(A[i]%2 && sc){
				go=0;
				break;	
			}
			sc+=A[i]%2;
		}
		int sum=0;
		if(go){
			while(!s.empty()){
				int i;
				for(i=s.size()-1;i>0 && s[0]!=s[i];i--);	
				if(s[0]==s[i]){
					s.erase(0,1);
					if(i){
						sum+=s.size()-i;
						s.erase(i-1,1);
					}else{
						sum+=s.size()/2;
					}
				}
			}
			fout<<sum<<'\n';
		}else fout<<-1<<'\n';
	}
	return 0;
}
