//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2261

# include <bits/stdc++.h>

using namespace std;

string proc(vector <string> A){
	sort(A.begin(),A.end());
	string s="";
	for(int i=0;i<A.size();i++){
		s+=A[i];
	}
	return s;
}

int main(){
	int n;
	cin>>n;
	while(n){
		map <string,int> F;
		vector <string> V;
		F.clear();		
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				string s;
				cin>>s;
				V.push_back(s);
			}
			F[proc(V)]++;
			V.clear();
		}
		int m=0,sol=0;
		for(map <string,int>::iterator i=F.begin();i!=F.end();i++){
			if(m<i->second){
				sol=0;
				m=i->second;
				sol+=m;
			}else if(m==i->second){
				sol+=m;
			}
		}
		cout<<sol<<'\n';
		cin>>n;
	}
	return 0;
}
