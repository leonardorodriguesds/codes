#include <bits/stdc++.h>
using namespace std;

class  SegTree{
	vector<long long int> sgtree;
	int size;
	long long int neutral_element = 9223372036854775807;

	long long int func(long long int a, long long int b){
		return min(a, b);
	}
	long long int query(int index, int rgl, int rgr, int left, int right){
		if(rgr < left or right < rgl)
			return neutral_element;
		if(rgl >= left and rgr <= right)
			return sgtree[index];

		int middle = (rgl + rgr) / 2;
		return func(query(2 * index + 1, rgl, middle, left, right), query(2 * index + 2, middle + 1, rgr, left, right));
	}

	void update(int index, int rgl, int rgr, int i, int value){
		if(rgl == i and rgr == i){
			sgtree[index] += value;
			return;
		}
		if(rgl > i or rgr < i)
			return;
		int middle = (rgl + rgr) / 2;
		update(2 * index + 1, rgl, middle, i, value);
		update(2 * index + 2, middle + 1, rgr, i, value);
		sgtree[index] = func(sgtree[2 * index + 1], sgtree[2 * index + 2]);
	}

	public:
		SegTree(int n): sgtree(4 * n, 0){ size = n; }
        long long int query(int left, int  right){ return query(0 , 0, size - 1, left, right); }
        void update(int i, long long int vl){ update(0, 0, size - 1, i, vl); }
};

int main(){
	int n, q, i, l, r, t, ld;
	long long int num;
	scanf("%d %d", &n, &q);
	
	SegTree sgt(n);
	for(i = 0; i < n; i++){
		scanf("%I64d", &num);
		sgt.update(i, num);
	}
	for(i = 0; i < q; i++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %I64d", &ld, &num);
			sgt.update(ld - 1, num);
		} else {
			scanf("%d %d", &l, &r);
			printf("%I64d\n", sgt.query(l - 1, r - 1));
		}
	}
	return 0;
}