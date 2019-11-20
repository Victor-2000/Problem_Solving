//Condition of the problem: https://www.infoarena.ro/problema/base3

#include <bits/stdc++.h>
#define INF 0xfffffff
#define NMAX 16010
using namespace std;
 
string s;
int dist[NMAX],S[3];
bool V[NMAX*2],isS=0;
queue <int> q;
 
int main(){
	ifstream cin("base3.in");
	ofstream cout("base3.out");
	for(int i=0;i<NMAX;i++)dist[i]=INF;
	for(int i=0;i<3;i++){
		cin>>s;
		S[i]=s.size();
		for(int j=0;j<S[i];j++){
			if(s[j]=='1'){
				int dif=abs(S[i]-2*j-1);
				isS=1;
				dist[dif]=min(S[i],dist[dif]);
				if(!V[dif]){
					q.push(dif);
					V[dif]=1;
				}	
			}
		}
	}
	if(!isS)cout<<0;
	else{
		while(!q.empty()){
			int c=q.front();
			q.pop();
			for(int i=0;i<3;i++){
				int cc=abs(c-S[i]);
				if(dist[cc]>dist[c]+S[i]){
					dist[cc]=dist[c]+S[i];
					if(!V[cc]){
						q.push(cc);
						V[cc]=1;
					}
				}
			}
			V[c]=0;
		}
		if(dist[0]!=INF)cout<<dist[0];
		else cout<<0;
	}
	return 0;
}
