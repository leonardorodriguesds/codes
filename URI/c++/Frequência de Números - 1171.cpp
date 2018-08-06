#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

void count_occurrence(unordered_map<int,int>& m, vector<int>& v){
	for (auto itr = v.begin(); itr != v.end(); ++itr){
		++m[*itr];
	}
}

int main(){
	unsigned int n, i;
	cin >> n;
	unordered_map<int,int> occurrence;
	vector<int> numbers(n);
	for(i = 0; i < n; i++){
		cin >> numbers[i];
	}
	count_occurrence(occurrence, numbers);
	sort( numbers.begin(), numbers.end() );
	numbers.erase( unique( numbers.begin(), numbers.end() ), numbers.end() );
	for (i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " aparece " << occurrence[numbers[i]] << " vez(es)" << endl;
	return 0;
}
