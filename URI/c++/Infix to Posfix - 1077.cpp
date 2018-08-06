#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
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
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

string solveIt(string& exp){
    string ans;
    int n = sz(exp);
    stack<char> aux;
    for (int i = 0; i < n; i++){
        switch(exp[i]){
            case '^':
            case '(':
                aux.push(exp[i]);
                break;
            case '*':
            case '/':
                while(!aux.empty() and (aux.top() == '^' or aux.top() == '/' or aux.top() == '*')){
                    ans += aux.top();
                    aux.pop();
                }
                aux.push(exp[i]);
                break;
            case '+':
            case '-':
                while(!aux.empty() and aux.top() != '('){
                    ans += aux.top();
                    aux.pop();
                }
                aux.push(exp[i]);
                break;
                break;
            case ')':
                while(!aux.empty() and aux.top() != '('){
                    ans += aux.top();
                    aux.pop();
                }
                if(!aux.empty() and aux.top() == '(')
                    aux.pop();
                break;
            default:
                ans += exp[i];
        }
    }
    while(!aux.empty()){
        ans += aux.top();
        aux.pop();
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string exp;
        cin >> exp;
        printf("%s\n", solveIt(exp).c_str());
    }
    return 0;
}