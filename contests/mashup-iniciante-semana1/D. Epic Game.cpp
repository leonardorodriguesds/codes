#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int table[1000][1000];

int gcd(int x, int y){
    if(y == 0) 
        return x;
    if(table[x][y] != -1)
        return table[x][y];
    int ans = gcd(y, x % y);
    table[x][y] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    while(n){
        int simon = gcd(a, n);
        if(n >= simon){
            n -= simon;
        } else {
            printf("1\n");
            return 0;
        }
        int antisimon = gcd(b, n);
        if(n >= antisimon){
            n -= antisimon;
        } else {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}