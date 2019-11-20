//Condition of the problem: https://www.infoarena.ro/problema/z

# include <bits/stdc++.h>
 
using namespace std;
 
int s=0,t[3][1000],k=0,x,y,n,m;
 
int z(int x1,int y1,int x2,int y2, int val1, int val2)
{
	if (val1==val2) return val1;
	else {
	int sf = (val2-val1+1)/4;
	if (x<=x2-(x2-x1+1)/2 && y<=y2-(y2-y1+1)/2)
	 return z(x1,y1,x2-(x2-x1+1)/2,y2-(y2-y1+1)/2,val1,val1+sf-1);
	if (x>=x1+(x2-x1+1)/2 && y<=y2-(y2-y1+1)/2)
	 return z(x1+(x2-x1+1)/2,y1,x2,y2-(y2-y1+1)/2,val1+sf,val1+sf*2-1);
	if (x<=x2-(x2-x1+1)/2 && y>=y1+(y2-y1+1)/2)
	 return z(x1,y1+(y2-y1+1)/2,x2-(x2-x1+1)/2,y2,val1+sf*2,val1+sf*3-1);
	if (x>=x1+(x2-x1+1)/2 && y>=y1+(y2-y1+1)/2) 
	 return z(x1+(x2-x1+1)/2,y1+(y2-y1+1)/2,x2,y2,val1+sf*3,val2);
	}
}
 
int main(){
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin>>n>>k;
	for(int i=0;i<k;i++){
	 fin>>y>>x;
	 fout<<z(1,1,1<<n,1<<n,1,1<<(n*2))<<'\n';
	}  
	return 0;
}
