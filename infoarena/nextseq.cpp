//Condition of the problem: https://www.infoarena.ro/problema/nextseq

#include <bits/stdc++.h>
 
using namespace std;
 
int A[10010],B[10010],P[10010],m[10010],p,a,b;
 
void add1(int A[]){
	A[1]+=1;
	int t=A[1]/p,i=2;
	if(t)A[1]=0;
	while(t){
		if(i<=A[0])A[i]=(t+=A[i]);
		else {
			A[i]=0;
			A[0]=i;
		}
		t/=p;
		if(t)A[i]=0;
		i++;
	}
}
 
int cmp(int A[],int B[]){
	if(A[0]>B[0])return 1;
	else if(A[0]<B[0]) return -1;
	for(int i=A[0];i>=1;i--){
		if(A[i]>B[i])return 1;
		else if(A[i]<B[i]) return -1;
	}
	return 0;
}
 
int main(){
	ifstream cin("nextseq.in");
	ofstream cout("nextseq.out");
	cin>>p>>b>>a;
	for(int i=0;i<p;i++){
		cin>>P[i];
	}
	sort(P,P+p);
	for(int i=0;i<p;i++){
		m[P[i]]=i;
	}
	int c;
	B[0]=b;
	for(int i=1;i<=b;i++){
		cin>>c;
		B[b-i+1]=m[c];
	}
	A[0]=a;
	for(int i=1;i<=a;i++){
		cin>>c;
		A[a-i+1]=m[c];
	}
	int s=0;
	while(cmp(A,B)!=0){
		add1(B);
		s++;
	}
	cout<<s-1;
}
