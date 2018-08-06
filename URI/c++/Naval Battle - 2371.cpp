#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int n, m, i, k, l, c, p = 0;
	scanf("%d %d", &n, &m);
	string board[n];
	for(i = 0; i < n; i++){
		scanf("%s", board[i].c_str());
	}
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		scanf("%d %d", &l, &c);
		if(board[l - 1][c - 1] == '#'){
			board[l - 1][c - 1] = '.';
			if(l > 1){
				if(c > 1 && board[l - 2][c - 2] == '#'){
					continue;
				}
				if(c < m && board[l - 2][c] == '#')
					continue;
			}
			if(l < n){
				if(c > 1 && board[l][c - 2] == '#')
					continue;
				if(c < m && board[l][c] == '#')
					continue;
			}
			if(c > 1 && board[l - 1][c - 2] == '#')
				continue;
			if(c < m && board[l - 1][c] == '#')
				continue;
			p++;
		}
	}
	printf("%d\n", p);
	return 0;
}
