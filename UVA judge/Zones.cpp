//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3488

#include <bits/stdc++.h>

using namespace std;

const int MAX=1<<20+1;

pair <int,int> gr[21];
int n,no,m,val[21];

//ofstream fout("test.out");

int main(){
	cin>>n>>no;
	int x=0;
	while(n){
		for(int i=0;i<n;i++){
			cin>>val[i];
		}
		cin>>m;
		for(int i=0;i<m;i++){
			int c,nr,p=0;
			cin>>nr;
			for(int j=0;j<nr;j++){
				cin>>c;
				p|=1<<(c-1);
			}
			cin>>c;
			gr[i].first=p;
			gr[i].second=c;
		}
		int cSum=0,mSum=0,max=0;
		for(int i=0;i<(1<<(n+1));i++){
			if(__builtin_popcount(i)==no){
				cSum=0;
				for(int j=0;j<n;j++){
					if(i & (1<<j)){
						cSum+=val[j];
					}
				}
				for(int j=0;j<m;j++){
					int cou=__builtin_popcount(i & gr[j].first)-1;
					if(cou>0){
						cSum-=cou*gr[j].second;
					}
				}
				if(cSum>mSum){
					mSum=cSum;
					max=i;				
				}else if(cSum==mSum && (i&(-i))<(max&(-max))){
					max=i;					
				}
			}
		}
		x++;
		//fout<<"Case Number  "<<x<<"\n";
		printf("Case Number  %d\n",x);
		//fout<<"Number of Customers: "<<mSum<<"\n";
		printf("Number of Customers: %d\n",mSum);
		printf("Locations recommended:");
		//fout<<"Locations recommended:";
		int p=0;
		while(max){
			p++;
			if(max%2){
				printf(" %d",p);
				//fout<<" "<<p;
			}
			max>>=1;
		}
		printf("\n\n");
		//fout<<"\n\n";
		cin>>n>>no;
	}
	return 0;
}
