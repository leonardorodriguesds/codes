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
vi div(int n);
string rotatestring(string, int, int);

vi div(int n){
    vi result;
    for (int i = 2; i * i <= n; i++){
        if(!(n % i)){
            result.push_back(i);
            if(i != (n / i)) result.push_back((n / i));
        }
    }
    result.push_back(n);
    return result;
}

string rotatestring(string str, int d, int n){
    string rotate = str.substr(0, d);
    reverse(all(rotate));
    string result = rotate + (((n - 1) >= d)? str.substr(d, (n - 1)) : "");
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    string str;
    cin >> str;
    vi divisors = div(n);
    sort(all(divisors));
    for(int d: divisors)
        str = rotatestring(str, d, n);
    cout << str << endl;
    return 0;
}