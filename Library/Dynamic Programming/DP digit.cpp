/** Solve questions like count the number of integers ‘x‘ between 
 * two integers say ‘a‘ and ‘b‘ such that x satisfies a specific property 
 * that can be related to its digits.
 * 
 * Key Concept (geeksforgeeks)
 * * 1. Let given number x has n digits. The main idea of digit DP is to 
 * * first represent the digits as an array of digits t[]. Let’s say a we have 
 * * tntn-1tn-2 … t2t1 as the decimal representation where ti (0 < i <= n) 
 * * tells the i-th digit from the right. The leftmost digit tn is the 
 * * most significant digit.
 * 
 * * 2. Now, after representing the given number this way we generate 
 * * the numbers less than the given number and simultaneously calculate 
 * * using DP, if the number satisfy the given property. We start generating 
 * * integers having number of digits = 1 and then till number of digits = n. 
 * * Integers having less number of digits than n can be analyzed by 
 * * setting the leftmost digits to be zero.
 * 
 * Time Complexity:
 * * There are total idx*sum*tight states and we are performing 0 to 9 
 * * iterations to visit every state. Therefore, The Time Complexity will 
 * * be O(10*idx*sum*tight). Here, we observe that tight = 2 and idx can be 
 * * max 18 for 64 bit unsigned integer and moreover, the sum will be max 9*18 ~ 200. 
 * * So, overall we have 10*18*200*2 ~ 10^5 iterations which can be easily executed 
 * * in 0.01 seconds.
 * 
 * FONTE: https://www.geeksforgeeks.org/digit-dp-introduction/
 * 
 * Leonardo Rodrigues de Souza.
 */

#include <bits/stdc++.h>
using namespace std;
#define fill(t,v)           memset(t, v, sizeof(t))
typedef vector<int> vi;
typedef long long ll;
ll table[20][180][2];
ll solveIt(int, int);
ll dp(int, int, int, vi&);
vi getdigits(int);

vi getdigits(int x){
    vi ans;
    while(x > 0){
        ans.push_back(x % 10);
        x /= 10;
    }
    return ans;
}


ll solveIt(int l, int r){
    fill(table, -1);
    vi dig = getdigits(l - 1);
    ll ans = dp(dig.size() - 1, 0, 1, dig);
    dig = getdigits(r);
    ans = dp(dig.size() - 1, 0, 1, dig) - ans;
    return ans;
}

ll dp(int idx, int sum, int tight, vi& digits){
    if(idx == -1) return sum;
    ll& ans = table[idx][sum][tight];
    if(ans != -1 and tight != 1) return ans;
    ll ret = 0;
    int k = (tight)? digits[idx] : 9;
    for(int i = 0; i <= k; i++) 
        ret += dp(idx - 1, sum + i, (digits[idx] == i)? tight : 0, digits);
    if(!tight) ans = ret;
    return ret;
}

int main(){
    int l, r;
    scanf("%d %d", &l, &r);
    printf("digit sum for given range: %lld\n", solveIt(l, r));
    return 0;
}