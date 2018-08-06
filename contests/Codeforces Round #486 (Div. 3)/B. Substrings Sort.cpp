#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<string> words;
    vector<pair<long long, int>> sequence;
    map<int, int> letters[n];
    bool ans = true;
    for(int i = 0; i < n; i++){
        string word;
        cin >> words[i];
        word = words[i];
        int num = 0;
        for(int j = 0; j < word.size(); j++){
            num += (1 << word[j] - 'a');
            letters[i][word[j]]++;
        }
        sequence.push_back(make_pair(num, i));
    }
    sort(sequence.begin(), sequence.end());
    int j = 0;
    for(auto wd: sequence){
        int i = wd.second;
        int c = sequence[j + 1].second;
        for(auto letter: letters[i]){
            printf("%c => %d ", letter.first, letter.second);
            if(letters[c][letter.first] < letter.second){
                ans = false;
                break;
            }
        }
        j++;
    }
    
    printf("%s\n", (ans == true)? "YES" : "NO");
    if(ans){
        for(auto show: sequence)
            cout << show.second << endl;
    }
    return 0;
}