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

int queryUtils(int node, int b, int e, int L, int R, vi& segTree) {
    if (b >= L && e <= R) {
        return segTree[node];
    }

    if (b > R || e < L) {
        return neutral;
    }

    int mid = (b + e) >> 1, l = node << 1, r = node << 1 | 1;    
    return compare(queryUtils(l, b, mid, L, R, segTree), queryUtils(r, mid + 1, e, L, R, segTree));
}

int query(int n, int i, int j, vi& segTree) {
    return queryUtils(1, 0, n - 1, min(i, j), max(i, j), segTree);
}

void init_problem(int n, int q) {
    vi arr(n, neutral);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    vi segTree(max_size, 0);
    segmentTree(1, 0, n - 1, arr, segTree);

    while(q--) {
        int i, j;
        scanf2(i, j);
        cout << query(n, i, j, segTree) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    int n, q;
    while(cin >> n >> q) {
        init_problem(n, q);
    }
    return 0;
}