#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int n, i, j, z, count;
	while(scanf("%d", &n)){
		count = 0;
		if(n == 0)
			break;
		int numbers[n];
		for(i = 0; i < n; i++)
			scanf("%d", &numbers[i]);
		for(i = 0; i < n; i++){
			j = (i - 1 >= 0? i - 1: n - 1);
			z = (i + 1 <= n - 1? i + 1: 0);
			if((numbers[j] < numbers[i] && numbers[i] > numbers[z]) || (numbers[j] > numbers[i] && numbers[i] < numbers[z]))
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
