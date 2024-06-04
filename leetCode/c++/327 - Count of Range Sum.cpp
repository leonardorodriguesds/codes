#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
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
#define FOR(x,n) for(int x = 0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x = 1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x = int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x = int(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define mset(x, y) memset(&x, (y), sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

int neutral = 0;

int compare(int a, int b) {
    return a + b;
}

void segmentTree(int node, int b, int e, vi& arr, vi& segTree) {
    if (b == e) {
        segTree[node] = arr[b];
    } else {
        int mid = (b + e) >> 1, l = node << 1, r = node << 1 | 1;
        segmentTree(l, b, mid, arr, segTree);
        segmentTree(r, mid + 1, e, arr, segTree);
        segTree[node] = compare(segTree[l], segTree[r]);
    }
}

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        auto segTree = vi(2 * n + 2, lower - 1);
        segmentTree(1, 0, n - 1, nums, segTree);

        cout << "[";
        for(auto x: segTree)
            cout << x << ", ";
        cout << "]" << endl;
        int res = 0;
        for (int i = 1; i < segTree.size(); i++) {
            cout << segTree[i] << " :: " << "[" << (i << 1) << ", " << (i << 1 | 1) << "]" << endl; 
            if (segTree[i] >= lower && segTree[i] <= upper) {
                res++;
            }
        }       
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    auto nums = vi{0,-3,-3,1,1,2};
    auto lower = 3;
    auto upper = 5;
    auto res = Solution().countRangeSum(nums, lower, upper);
    cout << res << endl;
    return 0;
}