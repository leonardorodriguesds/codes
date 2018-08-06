#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, r, z, num;
  vector<int> numbers;
  scanf("%d %d %d", &n, &i, &r);
  for(z = 0; z < n; z++){
    scanf("%d", &num);
    numbers.push_back(num);
  }
  reverse(numbers.begin() + (--i), numbers.begin() + r);
  for(z = 0; z < n; z++){
    printf("%d ", numbers[z]);
  }
  printf("\n");
  return 0;
}
