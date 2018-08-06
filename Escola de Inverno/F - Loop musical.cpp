#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
	int n, i, j, z, count;
	while(scanf("%d", &n)){
		count = 0;
		if(n == 0)
			break;
		int numbers[n];
		for(i = 0; i < n; i++)
			scanf("%d", &numbers[i]);
		for(i = 0; i < n; i++){
			j = (i - 1 >= 0? i - 1: n - 1);
			z = (i + 1 <= n - 1? i + 1: 0);
			if((numbers[j] < numbers[i] && numbers[i] > numbers[z]) || (numbers[j] > numbers[i] && numbers[i] < numbers[z]))
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
