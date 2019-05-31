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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vii neg;
    deque<int> pos, zero;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a < 0) neg.emplace_back(a, i);
        else if (a > 0) pos.push_back(i);
        else zero.push_back(i);
    }
    sort(all(neg));

    if (zero.size() or (((int)neg.size()) % 2)) {
        if (((int)neg.size()) % 2)
            zero.push_front(neg.back().second), neg.pop_back();

        for(deque<int>::iterator it = zero.begin(); it < zero.end() - 1; ++it)
            cout << 1 << " " << *it + 1 << " " << *(it + 1) + 1 << endl;

        if ((int)zero.size() <= (n - 1)) cout << 2 << " " << zero.back() + 1 << endl; 
    }

    if (neg.size()){
        if (neg.size() > 1)
            for(vector<ii>::iterator it = neg.begin(); it < neg.end() - 1; ++it)
                cout << 1 << " " << (*it).second + 1 << " " << (*(it + 1)).second + 1 << endl;
        pos.push_front(neg.back().second);
    }
    
    for(deque<int>::iterator it = pos.begin(); it < pos.end() - 1; ++it)
        cout << 1 << " " << *it + 1 << " " << *(it + 1) + 1 << endl;
    return 0;
}