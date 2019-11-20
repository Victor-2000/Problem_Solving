//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=342
#include <bits/stdc++.h>

using namespace std;

//ofstream fout("test.out");
//ifstream fin("test.in");

string s1="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string s2="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
map <char,char> Ma;

int main(){
	string s;
	bool e=false;
	int l=s1.size();
	for(int i=0;i<l;i++)
		Ma[s1[i]]=s2[i];
	while(cin>>s){
		int l=s.size(),m=(l/2)+l%2;
		bool isPal=true,isMi=true;
		for(int i=0;i<m;i++){
			if(isPal && s[i]!=s[l-i-1])isPal=false;
			if(isMi && s[i]!=Ma[s[l-i-1]])isMi=false;
		}
		if(isPal && isMi) cout<<s<<" -- is a mirrored palindrome.\n\n";
		else if(isPal) cout<<s<<" -- is a regular palindrome.\n\n";
		else if(isMi) cout<<s<<" -- is a mirrored string.\n\n";
		else cout<<s<<" -- is not a palindrome.\n\n";
	}
	return 0;
}
