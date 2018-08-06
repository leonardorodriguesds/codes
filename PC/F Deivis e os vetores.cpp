#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, n, x, num, retrn = 0;
  vector<int> diffs;
  scanf("%d %d", &n, &x);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    num = (x > num? x - num : num - x);
    diffs.push_back(num);
  }
  for(i = 0; (i < n && !retrn); i++){
    scanf("%d", &num);
    if(find(diffs.begin(), diffs.end(), num) != diffs.end())
      retrn = 1;
  }
  printf("%d\n", retrn);
  return 0;
}
