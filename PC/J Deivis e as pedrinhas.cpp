#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, n;
  scanf("%d", &n);
  string stone;
  vector<string> stones;
  for(i = 0; i < n; i++){
    cin >> stone;
    stones.push_back(stone);
  }
  set<string> remaining(stones.begin(), stones.end());
  cout << remaining.size() << endl;
  return 0;
}
