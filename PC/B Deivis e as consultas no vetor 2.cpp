#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, q, i, start, end, middle, query, ans;
  scanf("%d %d", &n, &q);
  vector<int> numbers(n, 0);
  for(i = 0; i < n; i++)
    scanf("%d", &numbers[i]);
  sort(numbers.begin(), numbers.end());
  for(i = 0; i < q; i++){
    scanf("%d", &query);
    start = 0;
    end = n - 1;
    ans = n;
    while(start <= end){
      middle = (start + end) / 2;
      if(numbers[middle] <= query){
	ans = middle;
        start = middle + 1;
      } else
	end = middle - 1;	
    }
    if(ans == n) printf("-1\n");
    else printf("%d\n", numbers[ans]);
  }
  return 0;
}
