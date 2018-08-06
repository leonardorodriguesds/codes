#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    scanf("%d", &x);
    int left, right, middle, result = 0, ans = 0;
    for(int i = 0; i < sqrt(x); i++){
        left = 1;
        right = x;
        while(left <= right){
            middle = (left + right) / 2;
            if(pow(middle, i) > x)
                right = middle - 1;
            else{
                result = pow(middle, i);
                left = middle + 1;
            }
        }
        if(result > ans)
            ans = result;
    }
    printf("%d\n", ans);
    return 0;
}