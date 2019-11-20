//Condition of the problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1099

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define F(ss) find(ss)
#define TWIN(ff) ((ff%2)?(ff+1):(ff-1))
#define T(ff) TWIN(ff)
#define ENEMIES(a, b) (F(b) == F(T(a)) || F(a) == F(T(b)))
#define FRIENDS(a, b) (F(a) == F(b) || F(T(a)) == F(T(b)))
 
vector<int> p;
void init(int N) {
    p = vector<int> (N + 1);
    for (int i = 1; i < N + 1; i++)
        p[i] = i;
}
int find(int a) {
    return p[a] == a ? a : (p[a] = find(p[a]));
}
void Union(int a, int b) {
    p[find(a)] = find(b);
}
 
int main() {
    int N;
    int C, f1, f2;
 
scanf("%d", &N);
        init(2 * N);
        while ((scanf("%d %d %d\n", &C, &f1, &f2) == 3)) {
            if (C == 0 && f1 == 0 && f2 == 0) break;
            f1 = 2*f1 +1, f2=2*f2+1;
            if (C == 1) {
                if (ENEMIES(f1, f2)) printf("-1\n");
                else  Union(f1, f2), Union(TWIN(f1), TWIN(f2));
            }
            if (C == 2) {
                if (FRIENDS(f1, f2)) printf("-1\n");
                else  Union(f1, TWIN(f2)), Union(f2, TWIN(f1));
            }
            if (C == 3) {
                if (FRIENDS(f1, f2)) printf("1\n");
                else printf("0\n");
            }
            if (C == 4) {
                if (ENEMIES(f1, f2)) printf("1\n");
                else printf("0\n");
            }
        }
 
    return 0;
}
