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

bool back_word(pair<char, int>& f, pair<char, int>& s){
    return (f.second < s.second);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    string str;
    cin >> str;
    vector<pair<char, int>> word;
    for(int i = 0; i < n; i++)
        word.push_back(make_pair(str[i], i));
    sort(all(word));
    word.erase(word.begin(), word.begin() + k);
    sort(all(word), back_word);
    for(auto e: word)
        printf("%c", e.first);
    printf("\n");
    return 0;
}