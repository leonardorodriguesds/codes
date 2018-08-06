#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){
    array<string, 10> factorialD = {"0", "0", "2", "3", "322", "5", "53", "7", "7222", "7332"};
    int n;
    scanf("%d", &n);
    string num;
    cin >> num;
    string ans = "";
    for (int i = 0; i < sz(num); i++){
        if(num[i] > '1'){
            ans += factorialD[(num[i] - '0')];
        }
    }
    sort(ans.begin(), ans.end(), greater<char>());
    cout << ans << endl;
    return 0;
}