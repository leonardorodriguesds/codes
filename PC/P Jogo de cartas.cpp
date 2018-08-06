#include <bits/stdc++.h>
using namespace std;

bool decreasing(int i, int j){
  return (i > j);
}
int main(){
  vector<int> devis, veras;
  int n, m, i, num, p_devis = 0, p_veras  = 0;
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    devis.push_back(num);
  }
  for(i = 0; i < m; i++){
    scanf("%d", &num);
    veras.push_back(num);
  }
  sort(devis.begin(), devis.end(), decreasing);
  sort(veras.begin(), veras.end(), decreasing);
  n = (n <= m? n : m);
  for(i = 0; i < n; i++){
    if(devis[i] > veras[i])
      p_devis++;
    else
      p_veras++;
  }
  printf("%d %d\n", p_devis, p_veras);
  return 0;
}
