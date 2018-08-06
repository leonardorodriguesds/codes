#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b, i, j, sum, result = 0;
  scanf("%d %d %d", &n, &a, &b);
  for(i = a; i <= n; i++){
    j = i;
    sum = 0;
    while(sum <= b && j > 0){
      sum += j % 10;
      j /= 10;
    }
    if(sum >= a && sum <= b){
      result += i;
    }
  }
  printf("%d\n", result);
  return 0;
}
