//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2162

#include<bits/stdc++.h>

using namespace std;

string av=" ,.?!()[]{}\n";

bool isLetter(char c){
	int i;
	for(i=0;i<12;i++)
		if(av[i]==c)return false;
	return true;
}

string s;

void change(){
	for(int i=0;i<s.size();i++){
		if(!isLetter(s[i]) && i<s.size()){
			s.erase(i,1);
			i--;
		}
	}
}

bool check(string s){
	char SQ[1000][1000];
	int l=sqrt(s.size()),k=0;
	string s1="",s2="",s3="",s4="";	
	for(int i=0;i<l;i++)
	for(int j=0;j<l;j++){
		SQ[i][j]=s[k];
		k++;
	}	
	for(int i=0;i<l;i++)
	for(int j=0;j<l;j++){
		s1+=SQ[i][j];
		s2+=SQ[j][i];
		s3+=SQ[l-i-1][l-j-1];
		s4+=SQ[l-j-1][l-i-1];	
	}
	return (s1==s2 && s3==s4 && s1==s3);
}

int main(){
	int n;
	cin>>n;
	getline(cin,s);
	for(int i=1;i<=n;i++){
		getline(cin,s);
		change();
		printf("Case #%d:\n",i);
		if (sqrt(s.size())==(int)sqrt(s.size())){
			if(check(s))printf("%d\n",(int)sqrt(s.size()));
			else printf("No magic :(\n");
		}else printf("No magic :(\n");	
	}
	return 0;
}
