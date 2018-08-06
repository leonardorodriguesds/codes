#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned int i, x, divisors = 0;
  scanf("%u", &x);
  for(i = 1; i * i <= x; i++){
    if(x % i == 0){
      divisors++;
      if(i != (x / i)) divisors++;
    }
  }
  printf("%d\n", divisors);
  return 0;
}
