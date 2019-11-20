//Condition of the problem: https://infoarena.ro/problema/tabela
#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("tabela.in");
ofstream fout("tabela.out");
 
long long l,c;
 
/*Am observat ca rezolvarea se rezuma la o formula elementara (l-1 xor c-1. 
Dece l-1 si c-1? deoarece incepem de la valoarea 0 si coloanele si randurile incep de la 1)*/
int main(){
	fin>>l>>c;
	l--;c--;
	fout<<(l^c);
	return 0;
}
