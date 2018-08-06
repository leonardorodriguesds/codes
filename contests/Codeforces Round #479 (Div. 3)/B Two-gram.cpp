#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, count = 0;
    scanf("%d", &n);
    string s, two, ans;
    cin >> s;
    map<string, int> two_gram;
    for(int i = 0; i < n - 1; i++){
        two = "";
        two += s[i];
        two += s[i + 1];
        two_gram[two]++;
    }
    for(auto par: two_gram){
        if(par.second > count){
            ans = par.first;
            count = par.second;
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}