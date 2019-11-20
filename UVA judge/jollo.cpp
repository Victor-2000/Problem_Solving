//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3399

#include <bits/stdc++.h>

using namespace std;

int main(){
	bool iF[53];
	int M[3],F[4];
	bool bF[4];
	scanf("%d %d %d %d %d",&F[0],&F[1],&F[2],&M[0],&M[1]);
	while(F[0]){
		for(int i=1;i<=52;i++)iF[i]=1;
		bF[0]=bF[1]=bF[2]=1;
		iF[F[0]]=iF[F[1]]=iF[F[2]]=iF[M[0]]=iF[M[1]]=0;
		sort(F,F+3);
		sort(M,M+2);
	/*	cout<<"Sort:\n";
		for(int i=0;i<3;i++) cout<<F[i]<<' ';
		cout<<"\n";
		for(int i=0;i<2;i++) cout<<M[i]<<' ';
		cout<<'\n';*/
		int c=0,w=0;
		for(int i=0;i<3;i++) bF[i]=1;
		for(int i=1;i>=0;i--){
			int j;
				for(j=0;j<3;j++){
					if(bF[j] && F[j]>M[i]){
						bF[j]=0;
						c++;
						break;	
					} 
				}
			if (j==3){
				for(int j=0;j<3;j++){
					if(bF[j]){
						bF[j]=0;
						w++;
						break;
					}
				}
			}	
		}
	//	cout<<"c= "<<c<<'\n';
		if(w==2){
			int i=1;
			while(!iF[i]) i++;
			cout<<i<<'\n';
		}else if(c!=2){
			int s;
			for(s=0;s<3;s++) if(bF[s]) break;
			int i;
	//	cout<<"s= "<<s<<'\n';
			for(i=F[s];i<=52;i++){
				if(iF[i]){
					printf("%d\n",i);
					break;
				}
			}
			if (i>52) printf("-1\n");
		} else printf("-1\n");
	scanf("%d %d %d %d %d",&F[0],&F[1],&F[2],&M[0],&M[1]);
	}
	return 0;
}
