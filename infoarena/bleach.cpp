//Condition of the problem: https://www.infoarena.ro/problema/bleach

# include <bits/stdc++.h>
using namespace std;
long long n,h[1000000];
int k;

long long scalc(long long &x,int i)//O(1)
{ 
	long long s=0;
     	if (x<h[i]){
        	s+=h[i]-x;
        	x+=h[i]-x;
      	} 
    x+=h[i];
 	return s;
}

void heapify(int i,int k)
{
    int m=i;
    if(h[i*2+1]<h[m]&&i*2+1<=k) m=i*2+1;
	if(h[i*2+2]<h[m]&&i*2+2<=k) m=i*2+2;
    if (m!=i){
        swap(h[m],h[i]);
        heapify(m,k);
    }
}

int main(){
    ifstream fin("bleach.in");
    ofstream fout("bleach.out");
    long long c,x=0,s=0;
    fin>>n>>k;
    if (n-1<k) k=n-1;
	for (int i = 0;i<=k;i++){
        fin>>c;
        h[i]=c;
    }
    for (int i = k;i>=0;i--)
		heapify(i,k);
	if (k!=n-1)
    for (int i = 0;i<n-k-1;i++){
        s+=scalc(x,0);
		fin>>c;
        h[0]=c;
		heapify(0,k);
    }
    for (int i = k;i>=0;i--){
        heapify(0,i);
		s+=scalc(x,0);
        swap(h[i],h[0]);
    }
    fout<<s;
    return(0);
}
