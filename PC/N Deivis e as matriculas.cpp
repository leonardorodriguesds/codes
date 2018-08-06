#include <bits/stdc++.h>
using namespace std;

int main(){
  string name;
  vector<string> names;
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    cin >> name;
    names.push_back(name);
  }
  vector<string> order(names);
  sort(order.begin(), order.end());
  for(i = 0; i < n; i++){
    vector<string>::iterator indx = lower_bound(order.begin(), order.end(), names[i]);
    int index = indx - order.begin();
    cout << index << " ";
  }
  cout << endl;
  return 0;
}
