#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> numbers;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%ld", &aux);
        numbers.push_back(aux);
    }
    return 0;
}