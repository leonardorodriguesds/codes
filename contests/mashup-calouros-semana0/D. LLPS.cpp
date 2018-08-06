#include <bits/stdc++.h>
using namespace std;

string subsequence(string s){
    string result;
    int last = 0, cnt = 0, new_last = 0, last_count = 1;
    for (char ch = 'z'; ch >= 'a'; ch--){
        cnt = 0;
        for (int i = last; i < s.size(); i++){
            if (s[i] == ch)
                cnt++;
        }
        if (cnt >= last_count){
            for (int i = last; i < s.size(); i++){
                if (s[i] == ch){
                    if(i && s[i] < s[new_last])
                        continue;
                    result += ch;
                    new_last = i;
                }
            }
            last = new_last;
        }
    }
    return result;
}

int main(){
    string str;
    cin >> str;
    string ans = subsequence(str);
    cout << ans << endl;
    return 0;
}