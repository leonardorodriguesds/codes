#include <bits/stdc++.h>
using namespace std;
string smallestString(string input) {
    int chars = 0;
    int after[sizeof(input)];
    for (int i = input.length() - 1; i >= 0; i--) {
        chars |= 1 << (input[i] - 97);
        after[i] = chars;
    }
    string result = "";
    int start = 0, pos;
    while (chars) {
        for (int i = 0; i < 26; i++) {
            if (chars & (1 << i)) {
                pos = input.find('a' + i, start);
                if (chars == (chars & after[pos])) {
                    result += 'a' + i;
                    chars -= 1 << i;
                    break;
                }
            }
        }
        start = pos + 1;
    }
    return result;
}

int main(){
    int k;
    string str, ans = "";
    vector<string> substr;
    cin >> str >> k;
    int i = 0;
    for(i = 1; i < pow(2, str.size()); i++){
        ans = "";
        if(i & 1)
            ans += str[0];
        if(i & (1 << 1))
            ans += str[1];
        if(i & (1 << 2))
            ans += str[2];
        substr.push_back(ans);
        cout << i << ": " << ans << endl;
    }
    cout << substr[k - 1] << endl;
    return 0;
}