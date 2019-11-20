//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397

#include <bits/stdc++.h>

using namespace std;

#define left(n) n*2
#define right(n) n*2+1
#define MAX 4096000
int V[MAX],st[MAX],ls,lazy[MAX];

void build(int node,int L,int R){
	lazy[node]=0;
	if(L==R){
		st[node]=V[L];
		return;
	}
	int mid=(L+R)/2;
	build(left(node),L,mid);
	build(right(node),mid+1,R);
	st[node]=st[left(node)]+st[right(node)];
}


int query(int node,int l,int r,int L,int R){
	if(L>r||R<l) return -1;
	int mid=(L+R)/2;
	if(lazy[node]){
		switch(lazy[node]){
			case 1:{
				st[node]=R-L+1;
				break;
			}
			case 2:{
				st[node]=0;
				break;
			}
			case 3:{
				st[node]=R-L+1-st[node];
				break;
			}
		}
		if(lazy[node]<=2)lazy[left(node)]=lazy[right(node)]=lazy[node];
		else{
			switch(lazy[left(node)]){
				case 0:{
					lazy[left(node)]=3;
					break;
				}
				case 1:{
					lazy[left(node)]=2;
					break;
				}
				case 2:{
					lazy[left(node)]=1;
					break;
				}
				case 3:{
					lazy[left(node)]=0;
					break;
				}	
			}
			switch(lazy[right(node)]){
				case 0:{
					lazy[right(node)]=3;
					break;
				}
				case 1:{
					lazy[right(node)]=2;
					break;
				}
				case 2:{
					lazy[right(node)]=1;
					break;
				}
				case 3:{
					lazy[right(node)]=0;
					break;
				}	
			}
		}
		lazy[node]=0;
	}
	if(L>=l && R<=r) return st[node];
	int p1=query(left(node),l,r,L,mid),p2=query(right(node),l,r,mid+1,R);
	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return p2+p1;
}

void l_update(int node,int l,int r,int L,int R,int op){
	int mid=(L+R)/2;
		if(lazy[node]){
		switch(lazy[node]){
			case 1:{
				st[node]=R-L+1;
				break;
			}
			case 2:{
				st[node]=0;
				break;
			}
			case 3:{
				st[node]=R-L+1-st[node];
				break;
			}
		}
		if(lazy[node]<=2)lazy[left(node)]=lazy[right(node)]=lazy[node];
		else{
			switch(lazy[left(node)]){
				case 0:{
					lazy[left(node)]=3;
					break;
				}
				case 1:{
					lazy[left(node)]=2;
					break;
				}
				case 2:{
					lazy[left(node)]=1;
					break;
				}
				case 3:{
					lazy[left(node)]=0;
					break;
				}	
			}
			switch(lazy[right(node)]){
				case 0:{
					lazy[right(node)]=3;
					break;
				}
				case 1:{
					lazy[right(node)]=2;
					break;
				}
				case 2:{
					lazy[right(node)]=1;
					break;
				}
				case 3:{
					lazy[right(node)]=0;
					break;
				}	
			}
		}
		lazy[node]=0;
	}
	if(L>r||R<l) return;
	if(L>=l && R<=r){
		switch(op){
			case 1:{
				st[node]=R-L+1;
				break;
			}
			case 2:{
				st[node]=0;
				break;
			}
			case 3:{
				st[node]=R-L+1-st[node];
				break;
			}
		}
		if(op<=2)lazy[left(node)]=lazy[right(node)]=op;
		else{
			switch(lazy[left(node)]){
				case 0:{
					lazy[left(node)]=3;
					break;
				}
				case 1:{
					lazy[left(node)]=2;
					break;
				}
				case 2:{
					lazy[left(node)]=1;
					break;
				}
				case 3:{
					lazy[left(node)]=0;
					break;
				}	
			}
			switch(lazy[right(node)]){
				case 0:{
					lazy[right(node)]=3;
					break;
				}
				case 1:{
					lazy[right(node)]=2;
					break;
				}
				case 2:{
					lazy[right(node)]=1;
					break;
				}
				case 3:{
					lazy[right(node)]=0;
					break;
				}	
			}
		}
	return;
	}
	l_update(left(node),l,r,L,mid,op);
	l_update(right(node),l,r,mid+1,R,op);
	st[node]=st[left(node)]+st[right(node)];
}

void clear(){
	for(int i=0;i<MAX;i++){
		st[i]=V[i]=lazy[i]=0;
	}
}

#define l_update(a,b,op) l_update(1,a,b,0,ls-1,op)

ofstream fout("test.out");

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		clear();
		cout<<"Case "<<i<<":\n";
		int q,n,nc,nq=0;
		cin>>nc;
		string cs,s="";
		while(nc--){
			cin>>n;
			cin>>cs;
			for(int i=0;i<n;i++)s+=cs;
		}
		ls=s.size();
		for(int i=0;i<ls;i++)V[i]=s[i]-'0';
		build(1,0,ls-1);
		char c;
		int a,b;
		cin>>q;
		while(q--){
			cin>>c>>a>>b;
				switch (c){
					case 'F':{
					l_update(a,b,1);
					break;
				}
				case 'E':{
					l_update(a,b,2);
					break;
				}
				case 'I':{
					l_update(a,b,3);
					break;
				}
				case 'S':{
					cout<<'Q'<<++nq<<": "<<query(1,a,b,0,ls-1)<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}
