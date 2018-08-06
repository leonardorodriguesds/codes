#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, max_numbers = 0;
  scanf("%d", &n);
  int numbers[n];
  for(i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
    numbers[i] = (numbers[i] >= (i + 1)? numbers[i] - (i + 1): (n - (i + 1)) + numbers[i]);
  }
  map<int, int> counts;
  for(i = 0; i < n; i++){
    counts[numbers[i]]++;
    if(counts[numbers[i]] > max_numbers)
      max_numbers = counts[numbers[i]];
  }
  printf("%d\n", max_numbers);
  return 0;
}
