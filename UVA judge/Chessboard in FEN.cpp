//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1225

#include <bits/stdc++.h>

using namespace std;

char T[15][15];

void rook(int x,int y){
 bool str=false,stl=false,stu=false,std=false;
 for(int i=1;i<9;i++){
 	if(!str && x-i>0){
 		if(T[x-i][y]=='.') T[x-i][y]='x';
 		else if(T[x-i][y]!='x') str=true;
	 }
  	if(!stl && x+i<9){
 		if(T[x+i][y]=='.') T[x+i][y]='x';
 		else if(T[x+i][y]!='x') stl=true;
	 }
  	if(!stu && y+i<9){
 		if(T[x][y+i]=='.') T[x][y+i]='x';
 		else if(T[x][y+i]!='x') stu=true;
	 }
	if(!std && y-i>0){
 		if(T[x][y-i]=='.') T[x][y-i]='x';
 		else if(T[x][y-i]!='x') std=true;
	 } 
  }
}

void bishop(int x,int y){
  int val=x+y,val2=x-y;
  bool lu=false,ld=false,ru=false,rd=false;
 for(int i=y-1;i>0;i--){
  if (!rd && val-i>0){
  	if(T[val-i][i]=='.') T[val-i][i]='x';
  	else if(T[val-i][i]!='x')rd=true;
  }
  if(!ld && i+val2<9 && i+val2>0){
  	if (T[i+val2][i]=='.')
     T[i+val2][i]='x';
     else if(T[i+val2][i]!='x')ld=true;
   }
  }
for(int i=y+1;i<9;i++){
  if (!lu && val-i>0){
  	if(T[val-i][i]=='.') T[val-i][i]='x';
  	else if(T[val-i][i]!='x')lu=true;
  }
  if(!ru && i+val2<9 && i+val2>0){
  	if (T[i+val2][i]=='.')T[i+val2][i]='x';
     else if(T[i+val2][i]!='x')ru=true;
   }
  }
 }

void king(int x,int y){
 for(int i=x-1;i<=x+1;i++)
  for(int j=y-1;j<=y+1;j++)
  if (T[i][j]=='.')T[i][j]='x';
 }

 void knight(int x, int y){
    if (T[x+2][y+1]=='.')T[x+2][y+1]='x';
    if (T[x+2][y-1]=='.')T[x+2][y-1]='x';
    if (T[x-2][y+1]=='.')T[x-2][y+1]='x';
    if (T[x-2][y-1]=='.')T[x-2][y-1]='x';
    if (T[x+1][y+2]=='.')T[x+1][y+2]='x';
    if (T[x+1][y-2]=='.')T[x+1][y-2]='x';
    if (T[x-1][y+2]=='.')T[x-1][y+2]='x';
    if (T[x-1][y-2]=='.')T[x-1][y-2]='x';
  }

void pawn_w(int x, int y){
 if(T[x-1][y-1]=='.') T[x-1][y-1]='x';
 if(T[x-1][y+1]=='.') T[x-1][y+1]='x';
}

void pawn_b(int x, int y){
  if(T[x+1][y+1]=='.') T[x+1][y+1]='x';
 if(T[x+1][y-1]=='.') T[x+1][y-1]='x';
}

void queen(int x, int y){
 rook(x,y);
 bishop(x,y);
}

int main(){
 int row=1,col=1;
 char c='x';
 while(scanf("%c",&c)!=EOF){
  if (c=='/'){
              row++;
              col=1;
     } else if(c>'0' && c<'9'){
                for(int i=col;i<=col+c-'0';i++){
                T[row][i]='.';
                } 
                col+=c-'0';
                }else if(c!='\n'){
                 T[row][col]=c;
                 col++;
                }
  if(row==8&&col==9) {
	/*for(int i=1;i<9;i++){
		for(int j=1;j<9;j++)
			printf("%c",T[i][j]);
		cout<<'\n';
	}*/
	 for(int i=1;i<9;i++){
	 	for(int j=1;j<9;j++){
		  switch(T[i][j]){
			case 'k':king(i,j); break;
   			case 'K':king(i,j); break;
   			case 'q':queen(i,j); break;
   			case 'Q':queen(i,j); break;
   			case 'r':rook(i,j); break;
   			case 'R':rook(i,j); break;
   			case 'b':bishop(i,j); break;
   			case 'B':bishop(i,j); break;
   			case 'n':knight(i,j); break;
   			case 'N':knight(i,j); break;
   			case 'p':pawn_b(i,j); break;
   			case 'P':pawn_w(i,j); break;
   		}
	  }
	}
	int s=0;
	/*for(int i=1;i<9;i++){
		for(int j=1;j<9;j++)
			printf("%c",T[i][j]);
		cout<<'\n';
	}*/	
	for(int i=1;i<9;i++)
 		for(int j=0;j<9;j++)
   			if(T[i][j]=='.')s++;
 	cout<<s<<'\n';
	row=1;
	col=1;
  }
 }
 return 0;
}
