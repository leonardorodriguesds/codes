#include <bits/stdc++.h>
using namespace std;

int N = 10000000;
vector<int> primes(N, -1); 

set<int>factoring(int n){
    set<int> ans;
    while(n > 1){
        ans.insert(primes[n]);
        n /= primes[n];
    }

    return ans;
}

int main(){
    for(int x = 2; x < N; x++)
        if(primes[x] == -1){
            for(int m = x; m < N; m += x)
                primes[m] = x;
            } 
    int q, i, num;
    scanf("%d", &q);
    set<int> primes_q;
    set<int>::iterator it;
    for(i = 0; i < q; i++){
        scanf("%d", &num);
        primes_q = factoring(num);
        for (it = primes_q.begin(); it != primes_q.end(); ++it){
            printf("%d ", *it);
        }
        printf("\n");
    }
    return 0;
}