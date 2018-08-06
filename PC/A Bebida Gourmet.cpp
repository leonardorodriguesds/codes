#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned int n, i, q;
  vector<unsigned int>::iterator ans;
  scanf("%u", &n);
  vector<unsigned int> prices(n, 0);
  for(i = 0; i < n; i++)
    scanf("%u", &prices[i]);
  sort(prices.begin(), prices.end());
  scanf("%u", &n);
  for(i = 0; i < n; i++){
    scanf("%u", &q);
    ans = upper_bound(prices.begin(), prices.end(), q);
    printf("%d ", (ans - prices.begin()));
  }
  printf("\n");
  return 0;
}
