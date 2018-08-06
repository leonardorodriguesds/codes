#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, num1, num2, diff = 0;
  scanf("%d %d", &n, &num1);
  n--;
  while(n--){
    scanf("%d", &num2);
    if(abs(num1 - num2) > diff)
      diff = abs(num1 - num2);
    num1 = num2;
  }
  printf("%d\n", diff);
  return 0;
}
