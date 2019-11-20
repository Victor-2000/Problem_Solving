//Condition of the problem: https://www.infoarena.ro/problema/cerc3

#include <bits/stdc++.h>
 
using namespace std;
 
struct cerc{
	unsigned int x,y,r;
	float d;
};
 
ifstream fin("cerc3.in");
ofstream fout("cerc3.out");
 
vector <cerc> A[3000];
 
bool isb(cerc a,cerc b){
    return a.d<b.d;
}
 
int main(){
	cerc c;
	int m=0,n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>c.x>>c.y>>c.r;
		c.d = sqrt(c.x*c.x+c.y*c.y)+c.r;
		bool ok;
		ok=false;
		if(m){
			for(int j=0;j<m;j++){
					if(c.y*A[j].front().x == A[j].front().y*c.x){
						A[j].push_back(c);
						ok = true;
					}
				}
			if(!ok){
				A[m].push_back(c);
				m++;
			}  
		} else { 
				m++;
				A[0].push_back(c);
		}
	}
	int qmax = 1,p = 0;
	for(int i=0;i<m;i++){
		sort(A[i].begin(),A[i].end(),isb);
		int q = 1,s=A[i].size();
			cerc c;
			c = A[i][0];
			for(int j=1;j<s;j++){
				float dist = sqrt((A[i][j].x-c.x)*(A[i][j].x-c.x) + (A[i][j].y-c.y)*(A[i][j].y-c.y));
				if(dist > c.r + A[i][j].r){
					c = A[i][j];
					q++; 
				} 
			}
			if(q > qmax){
				qmax=q;
				p = 1;
			} else if(q==qmax) p++;
 }
	fout<<m<<' '<<qmax<<' '<<p;
	return 0;
}
