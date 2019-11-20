//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=525

#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	while(s!="Game Over"){
		int l=s.size(),sum=0,fn=0;
		bool count=0,bonus=0;
		for(int i=0;i<l;i++){
			if((i+1)%2 && fn<10){
				bonus=(!bonus && fn==9);
				if(s[i]<='9'&&s[i]>='0'){
					if(count){
						fn++;
						count=0;
					}else count=1;
					sum+=s[i]-'0';
				} else if(s[i]=='/'){
					fn++;
					count=0;
					sum+=10;
					if(s[i+2]<='9' && s[i+2]>='0') sum+=s[i+2]-'0';
					else sum+=10;
					sum-=s[i-2]-'0';
					if(bonus)break;
				} else {
					fn++;	
					count=0;
					sum+=10;
					if(s[i+2]<='9' && s[i+2]>='0') sum+=s[i+2]-'0';
					else sum+=10;
					if(s[i+4]<='9' && s[i+4]>='0') sum+=s[i+4]-'0';
					else if(s[i+4]=='/'){
							if(s[i+2]<='9' && s[i+2]>='0')
							sum-=s[i+2]-'0'; else sum-=10;
							sum+=10;
						} else sum+=10; 
					if(bonus)break;
					}
			}				
		
		}
	cout<<sum<<'\n';
	getline(cin,s);
	}
	return 0;
}
