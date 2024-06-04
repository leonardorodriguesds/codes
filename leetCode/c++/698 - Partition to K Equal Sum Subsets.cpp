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
    unordered_map<int, bool> mem;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        FOR(i, n)
            sum += nums[i];
        
        if (sum % k != 0)
            return false;

        int target_sum = sum / k;
        sort(all(nums));

        return dp(0, 0, n, target_sum, nums);
    }

    bool dp(int used, int current_sum, int n, int target_sum, vi& nums) {
        if (used == (1 << n) - 1)
            return current_sum == 0;

        FOR(i, n) {
            if ((used & (1 << i)) == 0 && current_sum + nums[i] < target_sum) {
                if (dp(used | (1 << i), ((current_sum + nums[i]) % target_sum), n, target_sum, nums)) {
                    
                }
            }
        }

        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    auto nums = vi{4,3,2,3,5,2,1};
    auto res = Solution().canPartitionKSubsets(nums, 4);
    cout << res << endl;
    return 0;
}