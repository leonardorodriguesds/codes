#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, num, smaller = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    if(num > smaller)
      smaller = num;
  }
  printf("%d\n", smaller);
  return 0;
}
