#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, num;
  set<int> numbers;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    if(numbers.find(num) != numbers.end())
      numbers.erase(num);
    else
      numbers.insert(num);
  }
  cout << numbers.size() << endl;
  return 0;
}
