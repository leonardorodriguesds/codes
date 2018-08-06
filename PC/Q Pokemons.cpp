#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, last = 0;
  scanf("%d", &n);
  int pokemon[n], wins[n];
  for(i = 0; i < n; i++){
    scanf("%d", &pokemon[i]);
    wins[i] = 0;
  }
  for(i = 1; i < n; i++){
    if(pokemon[last] > pokemon[i])
      wins[last]++;
    else{
      wins[i]++;
      last = i;
    }
  }
  for(i = 0; i < n; i++){
    printf("%d ", wins[i]);
  }
  printf("\n");
  return 0;
}
