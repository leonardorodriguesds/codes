#include <bits/stdc++.h>
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
#define bl "\n"
#define debugarr(arr)   if (DEBUG) { for(auto a: arr) { cout << a << " "; } cout << bl; }
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii> > vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int> > pqi;
typedef vector<pqi> vpqi;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int n = nums.size();
        vvi res;
        set<vector<int> > unique_results;

        unordered_map<int, vii> preprocess;
        FOR(i, n) {
            for(int j = i + 1; j < n; j++) {
                int key = nums[i] + nums[j];
                preprocess[key].emplace_back(i, j);
            }
        }

        FOR(i,n) {
            int key = -nums[i];
            if (preprocess.find(key) != preprocess.end()) {
                vii aux = preprocess[key];
                FOR(j, aux.size()) {
                    ii u = aux[j];
                    vi v(3);
                    v[0] = nums[i];
                    v[1] = nums[u.first];
                    v[2] = nums[u.second];
                    sort(v.begin(), v.end()); 
                    if (unique_results.find(v) == unique_results.end()) {
                        unique_results.insert(v);
                        res.push_back(v);
                    }
                }
            }                
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int n;
    cin >> n;
    vi numbers(n);
    FOR(i, n)
        cin >> numbers[i];

    Solution sol = Solution();
    vvi res = sol.threeSum(numbers);
    cout << "[";
    FOR(i, res.size()) {
        vi v = res[i];
        cout << "[";
        FOR(j, v.size()) { 
            cout << v[j] << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
