#include <bits/stdc++.h>
using namespace std;

vector<int> _fibonacci_;
int fibonacci(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else if(!(n < _fibonacci_.size()))
		_fibonacci_.push_back(fibonacci(n - 1) + fibonacci(n- 2));
	return _fibonacci_[n];
}

int main(){
	int n;
	_fibonacci_.push_back(0);
	_fibonacci_.push_back(1);
	scanf("%d", &n);
	printf("%d\n", fibonacci(n));
	return 0;
}
