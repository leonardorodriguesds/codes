#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
    #define DEBUG false
#else
    #define DEBUG true
#endif
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

ll nextPalindrome(ll num) {
    string s = to_string(num + 1);
    int n = s.size();
    string half = s.substr(0, (n + 1) / 2);
    string rev = half;
    if (n % 2) rev.pop_back();
    reverse(rev.begin(), rev.end());
    string pal = half + rev;
    if (stoll(pal) >= num + 1) return stoll(pal);
    
    // increment half and build again
    int halfNum = stoi(half) + 1;
    half = to_string(halfNum);
    rev = half;
    if (n % 2) rev.pop_back();
    reverse(rev.begin(), rev.end());
    return stoll(half + rev);
}

class Solution {
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    string toBase(ll num, int k) {
        string result;
        result.reserve(32); 
        while (num > 0) {
            result += char('0' + (num % k));
            num /= k;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isKMirror(int num, int k) {
        string str10 = to_string(num);
        if (!isPalindrome(str10)) return false;

        string strK = toBase(num, k);
        return isPalindrome(strK);
    }

    public:
        long long kMirror(int k, int n) {
            ll num = 0, res = 0;
            while (n > 0) {
                num = nextPalindrome(num);
                if (isPalindrome(toBase(num, k))) {
                    res += num;
                    n--;
                }
            }
            return res;
        }
    };

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int n, k;
    cin >> k >> n;

    auto sol = Solution();
    cout << sol.kMirror(k, n) << endl;
    
    return 0;
}