//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=131
#include <bits\stdc++.h>

using namespace std;

string s;
int n;

bool comp(char a, char b){
	if (tolower(a)==tolower(b))
		return a<b;
	else return tolower(a)<tolower(b);
}

int main(){
	cin>>n;
	while(n--){
		cin>>s;
		sort(s.begin(),s.end(),comp);
		do{
			cout<<s<<'\n';
		}while(next_permutation(s.begin(),s.end(),comp));
	}
	return 0;
}
