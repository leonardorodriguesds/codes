#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", n - max(a + 1, n - b) + 1);
    return 0;
}