#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, times = 1;
  double result = 1.0;
  scanf("%d %d", &a, &b);
  while(times <= b)
    times *= 10;
  result = (float) a * times + b;
  if(fmod(result, sqrt(result)) == 0.0)
    printf("Sim\n");
  else
    printf("Nao\n");
  return 0;
}
