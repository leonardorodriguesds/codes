#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  do {
    for(auto&& element : str)
      cout << element;
    cout << endl;
  } while (next_permutation(begin(str), end(str)));
  return 0;
}
