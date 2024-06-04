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

class Solution {
public:
    double dfs(string left, string right, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited) {
        if (graph.find(left) == graph.end()) return -1.0;
        if (left == right) return 1.0;

        visited.insert(left);

        for (const auto& u: graph[left]) {
            if (visited.find(u.first) == visited.end()) {
                double result = dfs(u.first, right, graph, visited);
                if (result != -1.0) {
                    return result * u.second;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        int i = 0;
        for(auto eq: equations) {
            string left = eq[0];
            string right = eq[1];
            double val = values[i++];

            graph[left].emplace_back(right, val);
            graph[right].emplace_back(left, 1.0/val);
        }

        vector<double> res = vector<double>();
        for(auto q: queries) {
            string left = q[0];
            string right = q[1];
            unordered_set<string> visited;
            res.push_back(dfs(left, right, graph, visited));
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    auto sol = Solution();
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> results = sol.calcEquation(equations, values, queries);

    for (double result : results) {
        cout << result << " ";
    }
    return 0;
}