#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x, i, num, indx = -2;
  scanf("%d %d", &n, &x);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    if(num >= x)
      indx = i;
  }
  printf("%d\n", indx + 1);
  return 0;
}

