#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    bool ans = true;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if((abs(a - c) > d)){
        if((abs(a - b) > d) || (abs(b - c) > d))
            ans = false;
    }
    printf("%s\n", (ans == true)? "Yes" : "No");
    return 0;
}