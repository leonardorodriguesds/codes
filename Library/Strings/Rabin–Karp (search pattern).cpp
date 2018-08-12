#include <bits/stdc++.h>
using namespace std;
#define sz(a)           ((int)(a.size()))
typedef long long ll;

class RabinKarp{
    int n, m, p;
    string sb;
    vector<ll> hsh, pw;

    public:
        RabinKarp(string str, int p, int m): sb(str), p(p), m(m){
            this->n = sz(str);
            hsh.resize(n), pw.resize(n);
            hsh[0] = str[0]; pw[0] = 1;
            for(int i = 1; i < n; i++){
                hsh[i] = ((hsh[i - 1] * p) + str[i]) % m;
                pw[i] = (pw[i - 1] * p) % m;
            }
        };
        ll hash(int i, int j){
            ll ans = hsh[j];
            if(i > 0) ans = (ans - ((hsh[i - 1] * 1ll * pw[j - i + 1]) % m) + m) % m;
            return ans;
        }
        ll gethash(string str, int z){
            ll ans = str[0];
            for(int i = 1; i < z; i++)
                ans = ((ans * p) + str[i]) % m;
            return ans;
        };
        int check(string str){
            int z = sz(str), i;
            ll lookfor = this->gethash(str, z);
            bool flag = true;
            for(i = 0; i < (this->n - z + 1) and flag; i++){
                flag = flag && !(this->hash(i, (i + z - 1)) == lookfor);
                if(!flag)
                    for(int j = 0; j < z and !flag; j++)
                        flag = (this->sb[i + j] != str[j]);
            }
            return (flag)? -1 : --i;
        };
};

int main(){
    string s, t;
    cin >> s >> t;
    RabinKarp aux(s, 256, 1000000007);
    printf("%d\n", aux.check(t));
    return 0;
}