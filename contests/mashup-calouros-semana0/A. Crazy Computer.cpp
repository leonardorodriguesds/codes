#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c, last, current, ans = 1;
    scanf("%d %d", &n, &c);
    scanf("%d", &last);
    for(int i = 0; i < n - 1; i++){
        scanf("%d", &current);
        if(current - last <= c)
            ans++;
        else
            ans = 1;
        last = current;
    }
    printf("%d\n", ans);
    return 0;
}