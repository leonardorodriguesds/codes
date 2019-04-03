#include <bits/stdc++.h>
using namespace std;
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
int solveIt(unsigned long long, int);
void solveItHelper(unsigned long long, int[2][2], int);
void solveItMul(int[2][2], int[2][2], int);

int solveIt(unsigned long long n, int b) {
    int F[2][2] = {{1, 1,}, {1, 0}};
    solveItHelper(n, F, b);
    return ((2 * F[0][0]) - 1) % b;
}

void solveItHelper(unsigned long long n, int F[2][2], int b) {
    if (n == 0 or n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};
    solveItHelper((n / 2), F, b);
    solveItMul(F, F, b);
    if (n % 2 != 0)
        solveItMul(F, M, b);
}

void solveItMul(int F[2][2], int M[2][2], int b) {
    int a1 = (((F[0][0] * M[0][0]) % b) + ((F[0][1] * M[1][0]) % b)) % b;
    int a2 = (((F[0][0] * M[0][1]) % b) + ((F[0][1] * M[1][1]) % b)) % b;
    int a3 = (((F[1][0] * M[0][0]) % b) + ((F[1][1] * M[1][0]) % b)) % b;
    int a4 = (((F[1][0] * M[0][1]) % b) + ((F[1][1] * M[1][1]) % b)) % b;
    F[0][0] = a1;
    F[0][1] = a2;
    F[1][0] = a3;
    F[1][1] = a4;
}

int main(){
    int b, i = 0;
    unsigned long long n;
    while(scanf("%llu %d", &n, &b) and !(n == 0ULL and b == 0))
        printf("Case %d: %llu %d %d\n", ++i, n, b, solveIt(n, b));
    return 0;
}