#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, q, l, r, result, i;
  scanf("%d %d", &n, &q);
  int numbers[n];
  for(i = 0; i < n; i++)
    scanf("%d", &numbers[i]);
  
  while(q--){
    result = 0;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    for(i = l; i <= r; i++)
      result += numbers[i];
    printf("%d\n", result);
  }
  return 0;
}
