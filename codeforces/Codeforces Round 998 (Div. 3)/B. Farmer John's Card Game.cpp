#include <bits/stdc++.h>
#include <set> // Alterado para set em vez de unordered_set
#ifdef ONLINE_JUDGE
    #define DEBUG false
#else
    #define DEBUG true
#endif

#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-9)
#define PI 3.141592653589793238462643383279502884
#define all(a) a.begin(), a.end()
#define fill(t,v) memset(t, v, sizeof(t))
#define sz(a) ((int)(a.size()))
#define LOG2(X) ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v) ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b) (scanf("%d %d", &a, &b))
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
#define debugarr(arr) if (DEBUG) { for(auto a: arr) { cout << a << " "; } cout << bl; }

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

void init_problem(int n) {}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vii cards;
        set<int> cow_set; 
        vector<int> cows_order; 

        int total_cards = n * m;
        FOR(i, n) {
            FOR(j, m) {
                int card_value;
                cin >> card_value;
                cards.emplace_back(card_value, i);
            }
        }

        sort(all(cards));
        int cnt = 0;

        if (DEBUG) {
            FOR(i, total_cards) {
                cout << cards[i].first << " <==> " << cards[i].second << endl;
            }
        }

        FOR(i, n) {
            ii& card = cards[i];
            if (DEBUG)
                cout << "insert: " << card.second << endl;

            if (cow_set.find(card.second) == cow_set.end()) { 
                cow_set.insert(card.second);
                cows_order.pb(card.second);
            }
            cnt++;

            if (cow_set.size() < cnt)
                break;
        }

        if (cnt < n) {
            cout << -1 << endl;
            continue;
        }

        int i = 0; 

        if (DEBUG) {
            cout << "cows ordem: ";
            FOR(i, n)
                cout << cows_order[i] << " ";
            cout << endl;
        }

        while(i < total_cards) {
            if (DEBUG)
                cout << cards[i].second << "<==> " << cows_order[i % n] << endl;
            if (cards[i].second == cows_order[i % n])
                i++;
            else break;
        }

        if (DEBUG)
            cout << "final: " << i << endl; 
        if (i == total_cards) {
            FOR(i, n) cout << cows_order[i] + 1 << " ";
            cout << endl;
        } else cout << -1 << endl;
    }
    return 0;
}