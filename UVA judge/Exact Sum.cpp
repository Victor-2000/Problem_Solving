//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1998

#include<bits/stdc++.h>

using namespace std;

int n,A[10010],b1=-1,b2,s;
bool start=true;

int bs(int ex,int h){
	int hi,lo;
	if(h<s/2){
		hi=ex-1;
		lo=0;
	}else if(h>s/2){
		hi=n-1;
		lo=ex+1;
	}else{
		if(ex&&A[ex-1]==h) return A[ex-1];
		if(ex<n-1&&A[ex+1]==h) return A[ex+1];
		return -1;
	}
	while(hi>lo+1){
		int m=(hi+lo)/2;
		if(A[m]<h){
			lo=m;
		}else if(A[m]>h){
			hi=m;
		}else return A[m];
	}
	if(A[lo]==h) return A[lo];
	if(A[hi]==h) return A[hi];
	return -1;
}

int main(){
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		sort(A,A+n);
		int v;
		cin>>s;
		b1=-1;
		for(int i=0;i<n;i++){
			v=s-A[i];
			int c=bs(i,v);
			if(c!=-1)
			if(abs(c-A[i])<abs(b2-b1)||b1==-1){
				b1=A[i];
				b2=c;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",b1,b2);
	}
}
