#include <bits/stdc++.h>
using namespace std;

int main(){
  int holes[10] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1}, num = 0, _holes_ = 0, __holes__, a, b, i, number;
  scanf("%d %d", &a, &b);
  num = a;
  for(i = a; i <= b; i++){
    number = i;
    __holes__ = 0;
    while(number > 0){
      __holes__ += holes[number % 10];
      number /= 10;
    }
    if(__holes__ > _holes_){
      num = i;
      _holes_ = __holes__;
    }
  }
  printf("%d\n", num);
  return 0;
}
