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
    int n, k;
    scanf("%d %d", &n, &k);
    vi x;
    vi y;
    for(int i = 0; i < n; i++){
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        x.push_back(xi);
        y.push_back(yi);
    }
    double ans = 0;
    for(int i = 1; i < n; i++)
        ans += (sqrt(pow((x[i] - x[i - 1]), 2) + pow((y[i] - y[i - 1]), 2)));
    double ki = (double)k;
    printf("%lf\n", (ans * (ki / 50.0)));
    return 0;
}