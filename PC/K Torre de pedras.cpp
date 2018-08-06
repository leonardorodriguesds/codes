#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> stones;
  int n, stone;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &stone);
    stones.insert(stone);
  }
  cout << stones.size() << endl;
  return 0;
}
