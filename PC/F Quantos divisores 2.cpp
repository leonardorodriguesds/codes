#include <bits/stdc++.h>
using namespace std;

int N = 10000000;
vector<int> primes(N, -1); 

int divisors(int n){
    int ans = 1;
    map<int, int> expoentes;
    while(n > 1){
        expoentes[primes[n]]++;
         n /= primes[n];
    }
    for(pair<int, int> p : expoentes)
        ans *= (p.second + 1);
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
    for(i = 0; i < q; i++){
        scanf("%d", &num);        
        printf("%d\n", divisors(num));
    }
    return 0;
}
close