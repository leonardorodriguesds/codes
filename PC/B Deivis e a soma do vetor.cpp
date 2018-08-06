#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, num, sum = 0;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    sum += num;
  }
  printf("%d\n", sum);
  return 0;
}
