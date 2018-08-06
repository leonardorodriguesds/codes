#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, num;
  vector<int> numbers;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    numbers.push_back(num);
  }
  sort(numbers.begin(), numbers.end());
  for(i = 0; i < n; i++){
    printf("%d ", numbers[i]);
  }
  printf("\n");
  return 0;
}
