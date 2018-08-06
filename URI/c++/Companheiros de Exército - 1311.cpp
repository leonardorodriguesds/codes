#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
	int n, b, i, start, end, i_start, i_end;
	vector<int>::iterator begin, s_end, _start_, _end_;
	while(cin >> n >> b){
		if(!n && !b)
			break;
		vector<signed int> soldiers(n);
		iota(soldiers.begin(), soldiers.end(), 1);
		for(i = 0; i < b; i++){
			begin = soldiers.begin();
			s_end = soldiers.end();
			cin >> start >> end;
			_start_ = find(begin, s_end, start);
			if(end != start){
				_end_ = find(begin, s_end, end);
			} else
				_end_ = _start_;
			i_start = distance(begin, _start_);
			i_end = distance(begin, _end_);
			soldiers.erase(begin + i_start, begin + i_end + 1);
			n -= (end - start) + 1;
			if(i_start <= 0)
				cout << "* ";
			else
				cout << soldiers[i_start - 1] << " ";
			if(i_start > (n - 1))
				cout << "*";
			else
				cout << soldiers[i_start];
			cout << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}
