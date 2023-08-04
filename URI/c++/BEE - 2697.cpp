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
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

void segmentTree(int node, int b, int e, vi& notas, vi& sumSegmentTree, vi& maxSegmentTree, vi& minSegmentTree) {
    if (b == e) {
        sumSegmentTree[node] = maxSegmentTree[node] = minSegmentTree[node] = notas[b];
    } else {
        int mid = (b + e) >> 1, l = node << 1, r = node << 1 | 1;
        segmentTree(l, b, mid, notas, sumSegmentTree, maxSegmentTree, minSegmentTree);
        segmentTree(r, mid + 1, e, notas, sumSegmentTree, maxSegmentTree, minSegmentTree);
        int min_value = min(minSegmentTree[l], minSegmentTree[r]), max_value = max(maxSegmentTree[l], maxSegmentTree[r]);
        minSegmentTree[node] = min_value, maxSegmentTree[node] = max_value, sumSegmentTree[node] = (sumSegmentTree[l] + sumSegmentTree[r]);
    }
}

array<int, 3> queryUtils(int node, int b, int e, int L, int R, vi& sumSegmentTree, vi& maxSegmentTree, vi& minSegmentTree) {
    if (b >= L && e <= R) {
        return {sumSegmentTree[node], maxSegmentTree[node], minSegmentTree[node]};
    }

    if (b > R || e < L) {
        return {0, -INF, INF};
    }

    int mid = (b + e) >> 1, l = node << 1, r = node << 1 | 1;
    array<int, 3> left = queryUtils(l, b, mid, L, R, sumSegmentTree, maxSegmentTree, minSegmentTree);
    array<int, 3> right = queryUtils(r, mid + 1, e, L, R, sumSegmentTree, maxSegmentTree, minSegmentTree);
    
    return {(left[0] + right[0]), max(left[1], right[1]), min(left[2], right[2])};
}

int query(int n, int i, int j, vi& sumSegmentTree, vi& maxSegmentTree, vi& minSegmentTree) {
    array<int, 3> ans = queryUtils(1, 0, n - 1, min(i, j), max(i, j), sumSegmentTree, maxSegmentTree, minSegmentTree);
    return ans[0] - ans[1] - ans[2];
}

void init_problem(int n, int b) {
    vi notas(n, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        notas[i] = x;
    }

    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    vi sumSegmentTree(max_size, 0);
    vi maxSegmentTree(max_size, -INF);
    vi minSegmentTree(max_size, INF);
    segmentTree(1, 0, n - 1, notas, sumSegmentTree, maxSegmentTree, minSegmentTree);

    ll res = 0;
    for(int i = 0; i <= n - b; i++) {
        res += query(n, i, i + b - 1, sumSegmentTree, maxSegmentTree, minSegmentTree);
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    int n, b;
    while(cin >> n >> b) {
        init_problem(n, b);
    }
    return 0;
}