//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=97
#include <bits/stdc++.h>

using namespace std;

const int MAX = 18000;

int main(){
int c,T[10000];
while(1){
   	int m=0,s=0;
   	while(scanf("%d", &T[m]) == 1) {
            if(T[m] == 0)
                break;
            m++;
        }
    if(T[0] == 0)
        break;
        
   	s=T[0];
	for(int i=1;i<m;i++){
   	  	if(s>T[i])s=T[i];
   	}
   	
	for(;s<=MAX;s++){
         int sc=0;
         for(int j=0;j<m;j++){
              if(s%(2*T[j])<T[j]-5)sc++;
         }
         if(sc==m)break;
   	}
	if (s>MAX)printf("Signals fail to synchronise in 5 hours\n");
	else printf("%02d:%02d:%02d\n",s/3600,s%3600/60,s%60);
	}
 return 0;
}
