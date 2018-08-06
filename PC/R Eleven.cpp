#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i, tmp, last_1 = 1, last_2 = 1;
  scanf("%d", &n);
  string result(n, 'o');
  while(last_2 <= n){
    result[last_2 - 1] = 'O';
    tmp = last_2;
    last_2 = last_1 + last_2;
    last_1 = tmp;
  }
  cout << result << endl;
  return 0;
}
