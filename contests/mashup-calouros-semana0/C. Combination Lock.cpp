#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    string first, second;
    cin >> first >> second;
    for(int i = 0; i < n; i++){
        int d1 = first[i] - '0';
        int d2 = second[i] - '0';
        int distance = abs(d1 - d2);
        int distance2 = d1 + 1 + 9 - d2;
        int distance3 = d2 + 1 + 9 - d1;
        distance = min(distance, distance2);
        distance = min(distance, distance3);
        if(distance == 9)
            distance = 1;
        ans += distance;
    }
    printf("%d\n", ans);
    return 0;
}