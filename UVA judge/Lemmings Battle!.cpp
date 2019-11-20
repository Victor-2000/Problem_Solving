//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=919

# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	queue <int> G,B;
	cin>>n;
	while(n--){
		multiset <int> SG,SB;
		SG.clear();
		SB.clear();
		int b,ng,nb;
		cin>>b>>ng>>nb;
		for(int i=0;i<ng;i++){
			int c;
			cin>>c;
			SG.insert(-c);
		}
		for(int i=0;i<nb;i++){
			int c;
			cin>>c;
			SB.insert(-c);
		}
		int mid=0;
		while(!SG.empty() && !SB.empty()){
		//	printf("B:%d <-> %d \n",-*SB.begin(),-*SG.begin());			
			multiset <int>:: iterator aux,gr=SG.begin(),bl=SB.begin();
			int actualB=min(b,min((int)SG.size(),(int)SB.size())); 
			for (int j=0;j<actualB;j++){
				gr=SG.begin();bl=SB.begin();
				if(*gr > *bl){
					int i=*bl-*gr;
					SG.erase(gr);
					SB.erase(bl);
					B.push(i);
				}else if(*gr<=*bl){
					int i=*gr-*bl;
					SG.erase(gr);
					SB.erase(bl);
					if(i){	
						G.push(i);
					}else mid++;
				}
			}
			while(!G.empty()){
				SG.insert(G.front());
				G.pop();
			}
			while(!B.empty()){
				SB.insert(B.front());
				B.pop();
			}
			mid=0;
		}
		if(SB.empty() && !SG.empty()){
			printf("green wins\n");
			while(!SG.empty()){
				cout<<-*SG.begin()<<'\n';
				SG.erase(SG.begin());
			}
		} else if(SG.empty() && !SB.empty()){
			printf("blue wins\n");
			while(!SB.empty()){
				cout<<-*SB.begin()<<'\n';
				SB.erase(SB.begin());
			}
		} else {
			printf("green and blue died\n");
		}
		SB.clear();
		SG.clear();
		if(n)cout<<'\n';
	}
	return 0;
}
