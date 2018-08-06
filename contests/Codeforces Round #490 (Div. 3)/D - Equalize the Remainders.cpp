#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){
    string s;
    int n, m;
	scanf("%d %d", &n, &m);
    vi numbers, rem[n];
	for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        numbers.push_back(aux);
        rem[(aux % m)].push_back(i);
    }
    long long ans = 0;
    int z = 0;
    int end = (n / m);
    for(int i = 0; i < m; i++){
        while(rem[i].size() > end){
            z = max(z, i);
            while(rem[(z % m)].size() >= end)
                z++;            
            int aux = min((rem[i].size() - end), (end - rem[(z % m)].size()));
            while(aux--){
                numbers[rem[i].back()] += (z - i);
                rem[(z % m)].push_back(rem[i].back());
                rem[i].pop_back();
                ans += (z - i);
            }
        }
    }
    printf("%lld\n", ans);
    for(int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");
	return 0;
}