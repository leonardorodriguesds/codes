#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, j, num, sum = 0;
  scanf("%d", &n);
  int weights[n];
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    if((n & 1) && i < (n / 2) +  1 || !(n & 1) && i < (n / 2)){
      weights[i] = n + (n - (i + 1)) * i;
      j = (n & 1)? i - 1 : i;
    } else
      weights[i] = weights[j--];
    sum += num * weights[i];
  }
  printf("%d\n", sum);
  return 0;
}
