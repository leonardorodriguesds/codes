#include <bits/stdc++.h>
using namespace std;

long long get_factorial(long long num, int module){
  if(num < 2) return 1;
  return ((num * get_factorial(num - 1, module)) % module);
}

int main(){
  long long x, factorial;
  cin >> x;
  factorial = get_factorial(x, 1000000007);
  cout << factorial << endl;
  return 0;
}
