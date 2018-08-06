#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int count_lucky(string num){
    int ans = 0;
    for(int i = 0; i < num.size(); i++){
        if(num[i] == '4' or num[i] == '7')
            ans++;
    }
    return ans;
}

bool calc(string num){
    int lucky = count_lucky(num);
    if(lucky == 4 or lucky == 7)
        return true;
    return false;
}

int main(){
    string number;
    cin >> number;
    if(calc(number))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}