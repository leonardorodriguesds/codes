#include <bits/stdc++.h>
using namespace std;

int main(){
  	long long n, m, x, y, i, left, right, middle, amount, ans;
  	cin >> n >> m >> x >> y;
  	left = 0;
  	right = n;
  	while(left <= right){
  		middle = (left + right) / 2;
  		amount = m - (middle * x) + ((n - middle) * y);
  		if(amount < 0)
  			right = middle - 1;
  		else{
  			ans = middle;
  			left = middle + 1;
  		}
  	}
  	cout << ans << endl;
  	return 0;
}
