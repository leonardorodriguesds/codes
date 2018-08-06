#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, size;
  string _alphabet_, str;
  cin >> str >> _alphabet_;
  size = str.size();
  for(i = 0; i < size; i++){
    str[i] = _alphabet_[str[i] - 'a'];
  }
  cout << str << endl;
  return 0;
}
