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
int nums[2 * 100001], ctn[2 * 100001];

int main(){
    fill(ctn, 0);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
        ctn[nums[i]]++;
    }

    int j = 0, z = 0;
    for(int i = 0; i < 2 * 100001; i++)
        if (ctn[i] > ctn[j]) j = i;

    while (nums[z] != j) z++;

    cout << n - ctn[j] << endl;
    for(int i = z - 1; i >= 0; i--) {
        if (nums[i] != j)
            cout << ((nums[i] < j)? 1 : 2) << " " << i + 1 << " " << i + 2 << endl;
    }
    for(int i = z + 1; i < n; i++)
        if (nums[i] != j)
            cout << ((nums[i] < j)? 1 : 2) << " " << i + 1 << " " << i << endl;
    return 0;
}