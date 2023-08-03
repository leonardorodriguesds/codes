#include <bits/stdc++.h>
#include <climits>
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

void dfs(vector<vii>& tree, vi& euler, vector<ll>& height, vi& visited, vi& first, int node, ll h = 0) {
    visited[node] = 1;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for(auto e: tree[node]) {
        int v, dt;
        tie(dt, v) = e;
        if (!~visited[v]) {
            dfs(tree, euler, height, visited, first, v, h + (ll)dt);
            euler.push_back(node);
        }
    }
}

void segmentTree(vi& segTree, vi& euler, vector<ll>& height, int node, int b, int e) {
    if (b == e) {
        segTree[node] = euler[b];
    } else {
        int  mid = (b + e) >> 1;
        segmentTree(segTree, euler, height, node << 1, b, mid);
        segmentTree(segTree, euler, height, node << 1 | 1, mid + 1, e);
        int left = segTree[node << 1], right = segTree[node << 1 | 1];
        segTree[node] = height[left] < height[right] ? left : right;
    }
}

int queryUtils(vi& segTree, int node, vector<ll>& height, int b, int e, int L, int R) {
    if (b >= L && e <= R) {
        return segTree[node];
    }

    if (b > R || e < L) {
        return -1;
    }

    int  mid = (b + e) >> 1;
    int left = queryUtils(segTree, node << 1, height, b, mid, L, R);
    int right = queryUtils(segTree, node << 1 | 1, height, mid + 1, e, L, R);
    if (!~left) right;
    if (!~right) left;
    return height[left] < height[right] ? left: right;
}

int query(vi& segTree, vector<ll>& height, int n, int i, int j) {
    int left = min(i, j);
    int right = max(i, j);

    return queryUtils(segTree, 1, height, 0, n - 1, left, right);
}

void init_problem(int n) {
    vector<vii> tree(n);

    for (int i = 1; i < n; i++) {
        int ai, li;
        scanf2(ai, li);

        tree[i].emplace_back(li, ai);
        tree[ai].emplace_back(li, i);
    }

    vi visited(n, -1);
    vi first(n, -1);
    vi segTree(10 * n, 0);
    vi euler;
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    vector<ll> height(max_size + 1, LLONG_MAX);
    euler.reserve(2 * n);
    dfs(tree, euler, height, visited, first, 0);
    segmentTree(segTree, euler, height, 1, 0, euler.size() - 1);
    
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        scanf2(s, t);
        ll lca_height = height[query(segTree, height, euler.size(), first[s], first[t])];
        cout << (height[s] - lca_height) + (height[t] - lca_height) << (q ? " " : "");
    }
    cout << endl;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        init_problem(n);
    }
    return 0;
}