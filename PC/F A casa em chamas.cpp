#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  vector<int> values(n), weights(n);
  for(i = 0; i < n; i++){
    scanf("%d", &values[i]);
  }
  for(i = 0; i < n; i++){
    scanf("%d", &weights[i]);
  }
  queue<pair<int, int>> combinations;
  for(i = 0; i < n; i++){
    pair<int, int> combination;
    combination = make_pair(values[i], weights[i]);
    combinations.push(combination);
    for(j = i; (j < n) && (combination.second + weights[j] <= m); j++){
      combination.first += values[j];
      combination.second += weights[j];
      combinations.push(combination);
    }
  }
  while(combinations.size()){
    pair<int, int> elem;
    elem = combinations.front();
    combinations.pop();
    printf("%d - %d\n", elem.first, elem.second);
  }
  return 0;
}
