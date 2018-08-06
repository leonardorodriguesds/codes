#include <bits/stdc++.h>
using namespace std;

int main(){
  int year, i, digit, result;
  scanf("%d", &year);
  result = ++year;
  vector<bool> digits(10, false);
  while(year > 0){
    digit = year % 10;
    year /= 10;
    if(!digits[digit]){
      digits[digit] = true;
    } else {
      fill(digits.begin(), digits.end(), false);
      year = ++result;
    }
  }
  printf("%d\n", result);
  return 0;
}
