//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1508

#include <bits/stdc++.h>

using namespace std;

int mi=0;
string s;
vector <int> lt[60];

int dnq(int pos){
	int hi=lt[pos].size(),ind=-1,lo=0;
	while(hi>lo+1){
		int m=(hi+lo)/2;
		if(lt[pos][m]>mi){
			ind=m;
			hi=m;
		}else if(lt[pos][m]<mi) lo=m;
		else{
			ind=m;
			break;
		} 
	}
	if(ind!=-1){
		if(lt[pos][lo]<lt[pos][ind] && lt[pos][lo]>=mi)ind=lo;
		else if(lt[pos][hi]<lt[pos][ind] && lt[pos][hi]>=mi)ind=hi;
		mi=lt[pos][ind]+1;
		return lt[pos][ind];
	}else return -1;
}

int main(){
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		lt[s[i]-'A'].push_back(i);
	}
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		mi=0;
		int l=s.size(),c=-1,f=dnq(s[0]-'A'),ls=-1;
		if(f!=-1)
		for(int i=1;i<l-1;i++){
			c=dnq(s[i]-'A');	
			if(c==-1) break;
		}
		if(c!=-1||l==2)ls=dnq(s[l-1]-'A');
		if(l==1)ls=f;
		if(ls==-1) printf("Not matched\n");
		else printf("Matched %d %d\n",f,ls);
	}
	return 0;
}
